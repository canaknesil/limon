#include <limonInterpreter.h>

#include <parser.h>
#include <node.h>
#include <runHandler.h>
#include <environment.h>
#include <garbageCollector.h>
#include <limonException.h>
#include <mputil.h>

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;



Value *RunHandler::interpretFile(string filename, struct evaluationState state) {
  return LimonInterpreter::interpretFile(filename, state);
}


Value *LimonInterpreter::run_code_str(char *code_str, string filename, struct evaluationState state)
{
  Node *program = LimonParser::parse(code_str, filename);
  
  if (!program) {
    throw ExceptionStack("Parsing error in file \"" + filename + "\".");    
  }

  Value *val; // Don't free, freed by gc.
  try {
    val = program->evaluate(state);
  } catch (ExceptionStack &es) {
    delete program;
    throw es;
  }

  delete program;
  return val;
}



void LimonInterpreter::initializeLimon(struct evaluationState state,
				       struct initialConfig conf)
{
  // Put limon command-line arguments into environment.
  vector<Value *> il = vector<Value *>();
  for (int i=0; i<conf.limon_argc; i++) {
    il.push_back(new StrVal(state.garbageCollector, conf.limon_argv[i]));
  }
  state.environment->extend("argv", new ArrayVal(state.garbageCollector, il));

  // Run base library.
  if (conf.baseLibraryFlag) {
    char executablePath[PATH_MAX];
    getExecutablePath(executablePath, PATH_MAX);
    string baseLibraryFile = getDirectoryPart(executablePath) + "/" + RELATIVE_BASE_LIBRARY_FILE;

    try {
      interpretFile(baseLibraryFile, state); // return value ignored
    } catch (ExceptionStack &es) {
      es.push("Base library execution error.");
      throw es;
    }
  }

}



int LimonInterpreter::repl(string runFile, struct initialConfig initConf)
{
  try { // top most
    
    TriColorGC *garbageCollector = new TriColorGC();
    Environment<Value *> *environment = new Environment<Value *>(garbageCollector, nullptr);

    struct evaluationState state;
    state.garbageCollector = garbageCollector;
    state.environment = environment;
    state.functionStack = nullptr;
    
    try { // for gc
      
      try {
	initializeLimon(state, initConf);
      } catch (ExceptionStack &es) {
	es.push("Initialization error.");
	throw es;
      }

      if (runFile != "") {
	interpretFile(runFile, state);
      }

      while (true) {
	char *code_str = nullptr;
	try { // for repl
	  code_str = readline("\nlimon> ");
	  if (code_str == nullptr) {
	    cout << endl;
	    break; // EOF is entered
	  }
	  if (strlen(code_str) == 0) { // Skip empty lines
	    free(code_str);
	    continue;
	  }
	  add_history(code_str); // Add to readline history
	  
	  Value *val = nullptr;
	  try { // for code_str
	    val = run_code_str(code_str, "REPL", state);
	  } catch (ExceptionStack &es) {
	    free(code_str);
	    throw es;
	  }
	
	  if (!val) throw ExceptionStack("Evaluation error.");
	  cout << val->toString() << endl;
      
	} catch (ExceptionStack &es) {
	  const char *msg =  es.what();
	  cout << msg << endl; // cout since it is repl
	  delete[] msg;
	}
      } // while loop end
      
    } catch (ExceptionStack &es) {
      state.garbageCollector->collect();
      delete state.garbageCollector;
      throw es;
    }

    state.garbageCollector->collect();
    delete state.garbageCollector;
    
  } catch (ExceptionStack &es) {
    const char *msg = es.what();
    cerr << msg << endl;
    delete[] msg;
    return 1;
  } catch (exception &exc) {
    cerr << "Unstacked exception (PLEASE REPORT THIS BUG): " << exc.what() << endl;
    return 1;
  } catch (...) {
    cerr << "Unknown exception (PLEASE REPORT THIS BUG)." << endl;
    return 1;
  }
  
  return 0;
}


int LimonInterpreter::printAST_REPL()
{
  while (true) {
    char *code_str = readline("\nlimon(AST)> ");
    if (code_str == nullptr) {
      cout << endl;
      break; // EOF is entered
    }
    if (strlen(code_str) == 0) { // Skip empty lines
      free(code_str);
      continue;
    }
    add_history(code_str); // Add to readline history
    
    Node *program = LimonParser::parse(code_str, "REPL");
    free(code_str);

    if (!program) {
      cerr << "Parsing error." << endl;
      continue;
    }
    
    program->printAST();
    delete program;     
  }
  
  return 0;
}

int LimonInterpreter::printAST_file(string filename)
{
  FILE *f = fopen(filename.c_str(), "r");
  if (!f) {
    cerr << "Cannot open file \"" + filename + "\"." << endl;
    return 1;
  }

  char *code_str = file2string(f);
  fclose(f);
  
  Node *program = LimonParser::parse(code_str, filename);
  free(code_str);
  
  if (!program) {
    cout << "Parsing error." << endl;
    return 1;
  }
    
  program->printAST();
  delete program;

  return 0;
}



Value *LimonInterpreter::interpretFile(string filename, struct evaluationState state)
{
  char currDir[MAX_PATH_LEN];
  getcwd(currDir, MAX_PATH_LEN);

  char fnameCopy [MAX_PATH_LEN];
  strcpy(fnameCopy, filename.c_str());
  chdir(dirname(fnameCopy));

  strcpy(fnameCopy, filename.c_str());

  FILE *f = fopen(basename(fnameCopy), "r");
  if (!f)
    throw ExceptionStack("Cannot open file \"" + filename + "\".");

  char *code_str = file2string(f);
  fclose(f);

  Value *val = nullptr;
  try { // for code_str
    val = run_code_str(code_str, filename, state);
  } catch (ExceptionStack &es) {
    free(code_str);
    throw es;
  }
  free(code_str);

  chdir(currDir);
  return val;
}


int LimonInterpreter::interpretTopFile(string filename, struct initialConfig initConf)
{
  try { // top most
    
    TriColorGC *garbageCollector = new TriColorGC();
    Environment<Value *> *environment = new Environment<Value *>(garbageCollector, nullptr);

    struct evaluationState state;
    state.garbageCollector = garbageCollector;
    state.environment = environment;
    state.functionStack = nullptr;

    try { // for gc
      
      try {
	initializeLimon(state, initConf);
      } catch (ExceptionStack &es) {
	es.push("Initialization error.");
	throw es;
      }
  
      Value *val = LimonInterpreter::interpretFile(filename, state);
      if (!val) throw ExceptionStack("Top file execution error.");

      if (initConf.endValueFlag)
	cout << "Program ended with value: \n" << val->toString() << endl;

    } catch (ExceptionStack &es) {
      state.garbageCollector->collect();
      delete state.garbageCollector;
      throw es;
    }
  
    state.garbageCollector->collect();
    delete state.garbageCollector;

  } catch (ExceptionStack &es) {
    const char *msg = es.what();
    cerr << msg << endl;
    delete[] msg;
    return 1;
  } catch (exception &exc) {
    cerr << "Unstacked exception (PLEASE REPORT THIS BUG): " << exc.what() << endl;
    return 1;
  } catch (...) {
    cerr << "Unknown exception (PLEASE REPORT THIS BUG)." << endl;
    return 1;
  }

  return 0;
}


char *LimonInterpreter::file2string(FILE *f) {
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *code_str = (char *) malloc(fsize + 1);
  fread(code_str, 1, fsize, f);
  code_str[fsize] = '\0';
  
  return code_str;
}



string LimonInterpreter::getDirectoryPart(string path)
{
  size_t found = path.find_last_of("/\\");
  return path.substr(0, found);
}
