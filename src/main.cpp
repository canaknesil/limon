#include <limonInterpreter.h>

#include <iostream>
#include <string>
#include <getopt.h>

using namespace std;


void printUsage()
{
  cout << "Usage: limon [OPTION]... [FILE [ARG]...]" << endl;
  cout << endl;
  cout << "If FILE is not provided, REPL starts." << endl;
  cout << "Otherwise, Limon runs FILE and exits." << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "\t    --no-base    : Do not run base library." << endl;
  cout << "\t-r, --repl       : Run FILE, if exists, and start REPL." << endl;
  cout << "\t    --no-end-val : Do not display ending value." << endl;
  cout << "\t    --print-ast  : Pring AST mode." << endl;
  cout << "\t-h, --help       : Print usage." << endl;
  cout << endl;
}

int main(int argc, char *argv[])
{
  // Inputs that will be assigned by args.
  bool noBaseLibrary = false;
  string runFile = "";
  bool repl = false;
  bool noEndVal = false;
  bool printAST = false;

  // Parse command line parameters.
  int c;
  while (true) {
    int option_index = 0;
    static struct option long_options[] =
      {{"help"      , required_argument, 0, 'h'},
       {"no-base"   , no_argument      , 0,  0 },
       {"repl"      , no_argument      , 0, 'r'},
       {"no-end-val", no_argument      , 0,  0 },
       {"print-ast" , no_argument      , 0,  0 }};
    
    c = getopt_long(argc, argv, "hr",
		    long_options, &option_index);
    if (c == -1) // All arguments have been parsed.
      break;

    switch (c) {

    case 0:{ // Handle long only arguments.
      string optionStr = long_options[option_index].name;
      if      (optionStr == "no-base") noBaseLibrary = true;
      else if (optionStr == "no-end-val") noEndVal = true;
      else if (optionStr == "print-ast") printAST = true;
      break;
    }

    case 'r':
      repl = true;
      break;

    case 'h':
      printUsage();
      return 0;

    case '?':
      printUsage();
      return 1;

    default:
      cout << "Error while parsing command-line arguments." << endl;
      printUsage();
      return 1;
    }
  }

  if (optind < argc) {
    runFile = argv[optind++];
  }

  // The rest is passed to limon as its own command-line arguments.
  int limon_argc = argc - optind;
  char **limon_argv = &argv[optind];
  
  //
  // Start Limon.
  //
  
  if (printAST) {
    if (runFile == "") return LimonInterpreter::printAST_REPL();
    else return LimonInterpreter::printAST_file(runFile);
  }
  
  struct initialConfig initConf =
    { .baseLibraryFlag = !noBaseLibrary,
      .endValueFlag = !noEndVal,
      .limon_argc = limon_argc,
      .limon_argv = limon_argv
    };
  
  if (runFile == "") {
    return LimonInterpreter::repl(runFile, initConf);
  }

  if (repl) {
    return LimonInterpreter::repl(runFile, initConf);
  }

  return LimonInterpreter::interpretTopFile(runFile, initConf);
    
}
