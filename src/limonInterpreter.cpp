#include <limonInterpreter.h>

#include <parser.h>
#include <node.h>
#include <runHandler.h>
#include <environment.h>
#include <garbageCollector.h>

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;



Value *RunHandler::interpretFile(string filename,
				 GarbageCollector *gc,
				 Environment<Value *> *e) {
  return LimonInterpreter::interpretFile(filename, gc, e);
}


Value *LimonInterpreter::run_code_str(char *code_str, GarbageCollector *gc,
		    Environment<Value *> *e)
{
  Node* program = LimonParser::parse(code_str, "REPL");
  if (!program) throw LimonInterpreterException("Error while parsing.");
  
  Value *val = program->evaluate(gc, e);
  delete program;
  
  return val;
}



int LimonInterpreter::repl()
{
  try {
    
    TriColorGC *gc = new TriColorGC();
    Environment<Value *> *env = new Environment<Value *>(gc, nullptr);

    while (true) {
      char *code_str = nullptr;
      try {
	
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

	Value *val = run_code_str(code_str, gc, env);
	free(code_str);
	
	if (!val) throw LimonInterpreterException("Error while evaluating.");

	cout << val->toString() << endl;
      
      } catch (exception &exc) {
	cout << exc.what() << endl;
      }
    }

    gc->collect(set<GarbageCollector::Item *>());
    delete gc;

  } catch (exception &exc) {
    cout << exc.what() << endl;
  }
  
  return 0;
}


Value *LimonInterpreter::interpretFile(string filename,
				       GarbageCollector *gc,
				       Environment<Value *> *e)
{
  char currDir[MAX_PATH_LEN];
  getcwd(currDir, MAX_PATH_LEN);

  char fnameCopy [MAX_PATH_LEN];
  strcpy(fnameCopy, filename.c_str());
  chdir(dirname(fnameCopy));

  strcpy(fnameCopy, filename.c_str());

  Value *val = nullptr;
  try {

    FILE *f = fopen(basename(fnameCopy), "r");
    if (!f)
      throw LimonInterpreterException("Cannot open file \"" + filename + "\"");

    char *code_str = file2string(f);
    
    Node *program = LimonParser::parse(code_str, filename);
    fclose(f);
    free(code_str);

    if (!program) throw LimonInterpreterException("Parsing error.");

    val = program->evaluate(gc, e);
    delete program;

  } catch (exception &exc) {
    cout << exc.what() << endl;
  }

  chdir(currDir);
  return val;
}


int LimonInterpreter::interpretTopFile(string filename)
{
  Value *val = nullptr;
  try {

    TriColorGC *gc = new TriColorGC();
    Environment<Value *> *env = new Environment<Value *>(gc, nullptr);
    
    val = LimonInterpreter::interpretFile(filename, gc, env);
    if (!val) throw LimonInterpreterException("Error while evaluation.");
    
    cout << "Program ended with value: \n" << val->toString() << endl;

    gc->collect(set<GarbageCollector::Item *>());
    delete gc;

  } catch (exception &exc) {
    cout << exc.what() << endl;
  }
    
  if (val) return 0;
  else return 1;
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
