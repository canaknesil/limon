#include <functionStack.h>

#include <sstream>

using namespace std;

FunctionStack::FunctionStack(string functionName, string fileName, int line,
			     FunctionStack *next)
{
  this->functionName = functionName;
  this->fileName = fileName;
  this->line = line;
  this->next = next;
}

FunctionStack::~FunctionStack()
{
  if (this->next)
    delete this->next;
}

string FunctionStack::getFunctionName()
{
  return this->functionName;
}

string FunctionStack::getFileName()
{
  return this->fileName;
}

int FunctionStack::getLine()
{
  return this->line;
}

string FunctionStack::toString()
{
  ostringstream ss;
  ss << functionName << " (" << fileName << ": " << line << ")\n";
  if (next)
    ss << this->next->toString();
  return ss.str();
}
