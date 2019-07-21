#include <limonInterpreter.h>

#include <iostream>
#include <string>
#include <getopt.h>

using namespace std;


void printUsage()
{
  cout << "Usage: limon [OPTION]... [FILE]" << endl;
  cout << endl;
  cout << "If FILE is not provided, REPL starts." << endl;
  cout << "Otherwise, Limon runs FILE and exits." << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "\t    --no-base : Do not run base library." << endl;
  cout << "\t-r, --repl    : Run FILE, if exists, and start REPL." << endl;
  cout << "\t-h, --help    : Print usage." << endl;
  cout << endl;
}

int main(int argc, char *argv[])
{
  // Inputs that will be assigned by args.
  bool noBaseLibrary = false;
  string runFile = "";
  bool repl = false;

  // Parse command line parameters.
  int c;
  while (true) {
    int option_index = 0;
    static struct option long_options[] =
      {{"help"   , required_argument, 0, 'h'},
       {"no-base", no_argument      , 0,  0 },
       {"repl"   , no_argument      , 0, 'r'}};
    
    c = getopt_long(argc, argv, "hr",
		    long_options, &option_index);
    if (c == -1) // All arguments have been parsed.
      break;

    switch (c) {
    case 0:{ // Handle long only arguments.
      string optionStr = long_options[option_index].name;
      if (optionStr == "no-base") noBaseLibrary = true;
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

  if (optind < argc) {
    cout << "Extra command-line arguments: ";
    while (optind < argc)
      cout << argv[optind++] << " ";
    cout << endl;
    printUsage();
    return 1;
  }

  // Start Limon.
  if (runFile == "") {
    return LimonInterpreter::repl(runFile, !noBaseLibrary);
  }

  if (repl) {
    return LimonInterpreter::repl(runFile, !noBaseLibrary);
  }

  return LimonInterpreter::interpretTopFile(runFile, !noBaseLibrary);
    
}
