#ifndef FUNCTIONSTACK_H
#define FUNCTIONSTACK_H

#include <string>

using namespace std;


class FunctionStack
{
 public:
  FunctionStack();
  ~FunctionStack();
  string toString();
  void extend(string functionName, string fileName, int line);
  void pop();
  void reset();
 private:
  void deleteStack();
  struct functionStackNode
  {
    string functionName;
    string fileName;
    int line;
    struct functionStackNode *next;
  };
  struct functionStackNode *stack;
};

#endif
