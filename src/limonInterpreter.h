#ifndef LIMONINTERPRETER_H
#define LIMONINTERPRETER_H

#include <environment.h>
#include <garbageCollector.h>
#include <value.h>
#include <evaluationState.h>

#include <string>
#include <exception>

using namespace std;


#define MAX_PATH_LEN	(4096 + 255)
#define RELATIVE_BASE_LIBRARY_FILE "../base/base.lmn"


struct initialConfig
{
  bool baseLibraryFlag;
  bool endValueFlag;
  int limon_argc;
  char **limon_argv;
};


class LimonInterpreter
{
 public:

  /* 
   * This is the entry point when running files. The limon program
   * starts with a new environment and garbage collector.
   */
  static int interpretTopFile(string filename, struct initialConfig initConf);
  static Value *interpretFile(string filename, struct evaluationState state);

  /*
   * This is the entry point when starting the REPL.
   */
  static int repl(string runFile, struct initialConfig initConf);

  /*
   * Print AST mode. Print AST rather than evaluate.
   */
  static int printAST_REPL();
  static int printAST_file(string filename);

private:
  static Value *run_code_str(char *code_str,
			     string filename,
			     struct evaluationState state);
  static char *file2string(FILE *f);

  /*
   * Run initialization code before starting (run base library etc.).
   */
  static void initializeLimon(struct evaluationState state,
			      struct initialConfig initConf);
  static string getDirectoryPart(string path);
};



#endif
