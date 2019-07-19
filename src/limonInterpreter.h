#ifndef LIMONINTERPRETER_H
#define LIMONINTERPRETER_H

#include <environment.h>
#include <garbageCollector.h>
#include <value.h>

#include <string>
#include <exception>

using namespace std;


#define MAX_PATH_LEN	(4096 + 255)


class LimonInterpreter
{
 public:

  /* 
   * This is the entry point when running files. The limon program
   * starts with a new environment and garbage collector.
   */
  static int interpretTopFile(string filename);
  static Value *interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e);

  /*
   * This is the entry point when starting the REPL.
   */
  static int repl();

private:
  static Value *run_code_str(char *code_str,
			     GarbageCollector *gc,
			     Environment<Value *> *e);
  static char *file2string(FILE *f);
};


class LimonInterpreterException : public exception {
 public:
  LimonInterpreterException(string err) {
    this->err = err;
  }

  virtual const char* what() const throw() {
    return err.c_str();
  }
  
 private:
  string err;
};


#endif
