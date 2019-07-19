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

using namespace std;



Value *RunHandler::interpretFile(string filename,
				 GarbageCollector *gc,
				 Environment<Value *> *e) {
  return LimonInterpreter::interpretFile(filename, gc, e);
}



int LimonInterpreter::repl()
{
  try {
    
    TriColorGC *gc = new TriColorGC();
    Environment<Value *> *env = new Environment<Value *>(gc, nullptr);

    while (true) {
      cout << "limon> ";
      
      try {
	
	Node* program = LimonParser::parse(stdin, "REPL");
	if (!program) throw LimonInterpreterException("Error while parsing.");
      
	Value *val = program->evaluate(gc, env);
	delete program;

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
    
    Node *program = LimonParser::parse(f, filename);
    fclose(f);

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

