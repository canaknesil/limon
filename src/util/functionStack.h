#ifndef FUNCTIONSTACK_H
#define FUNCTIONSTACK_H

#include <string>

using namespace std;

class FunctionStack
{
 public:
  FunctionStack(string functionName, string fileName, int line,
		FunctionStack *next);
  ~FunctionStack();
  string getFunctionName();
  string getFileName();
  int getLine();
  string toString();
 private:
  string functionName;
  string fileName;
  int line;
  FunctionStack *next;
};

#endif
