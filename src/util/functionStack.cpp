#include <functionStack.h>

#include <sstream>

using namespace std;

FunctionStack::FunctionStack()
{
  this->stack = nullptr;
}

void FunctionStack::deleteStack()
{
  struct functionStackNode *node = this->stack;
  while (node) {
    struct functionStackNode *temp = node;
    node = node->next;
    delete temp;
  }
}

FunctionStack::~FunctionStack()
{
  deleteStack();
}

string FunctionStack::toString()
{
  ostringstream ss;
  struct functionStackNode *node = this->stack;

  while (node) {
    struct functionStackNode *temp = node;
    node = node->next;

    ss << temp->functionName << " (" << temp->fileName << ": "
       << temp->line << ")\n";
  }
  
  return ss.str();
}

void FunctionStack::extend(string functionName, string fileName, int line)
{
  struct functionStackNode *node = new struct functionStackNode;
  node->functionName = functionName;
  node->fileName = fileName;
  node->line = line;
  node->next = this->stack;

  this->stack = node;
}

void FunctionStack::pop()
{
  struct functionStackNode *temp = this->stack->next;
  delete this->stack;
  this->stack = temp;
}

void FunctionStack::reset()
{
  deleteStack();
  this->stack = nullptr;
}
