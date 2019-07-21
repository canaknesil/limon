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
  cout << "Otherwise limon runs FILE and exits." << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << "\t    --no-base : Do not run base library while initialization." << endl;
  cout << "\t-h, --help    : Print usage." << endl;
  cout << endl;
}

int main(int argc, char *argv[])
{
  // Inputs that will be assigned by args.
  bool noBaseLibrary = false;
  string runFile = "";

  // Parse command line parameters.
  int c;
  while (true) {
    int option_index = 0;
    static struct option long_options[] =
      {{"help",     required_argument, 0, 'h'},
       {"no-base",  no_argument,       0,  0 }};
    
    c = getopt_long(argc, argv, "h:",
		    long_options, &option_index);
    if (c == -1) // All arguments have been parsed.
      break;

    switch (c) {
    case 0:{ // Handle long only arguments.
      string optionStr = long_options[option_index].name;
      if (optionStr == "no-base") {
	noBaseLibrary = true;
      }
      break;
    }

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
    return LimonInterpreter::repl(!noBaseLibrary);
  }

  return LimonInterpreter::interpretTopFile(runFile, !noBaseLibrary);
    
}
