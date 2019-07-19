#include <limonInterpreter.h>

#include <iostream>
#include <string>

using namespace std;

void printUsage()
{
  cout << "Usage:" << endl;
  cout << "\tlimon            : REPL" << endl;
  cout << "\tlimon <filename> : Run file" << endl;
}

int main(int argc, char *argv[])
{
  if (argc == 1) {

    return LimonInterpreter::repl();
    
  } else if (argc == 2) {

    if (strcmp(argv[1], "help") == 0) {
      printUsage();
      return 0;
    } else {
      return LimonInterpreter::interpretTopFile(argv[1]);
    }
    
  } else {

    printUsage();
    return 1;
    
  }
}
