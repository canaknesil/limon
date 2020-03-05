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
  bool replFlag;
  string runFile;
  int limon_argc;
  char **limon_argv;
};


class LimonInterpreter
{
  friend class RunHandler;
  
 public:
  static int interpret(struct initialConfig initConf);
  
  /*
   * Print AST mode. Print AST rather than evaluate.
   */
  static int printAST(struct initialConfig initConf);
  static int printAST_REPL();
  static int printAST_file(string filename);

private:
  static Value *interpretFile(string filename, struct evaluationState state);
  static int repl(struct evaluationState state);
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
