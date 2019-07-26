#ifndef LIMONEXCEPTION_H
#define LIMONEXCEPTION_H

#include <vector>
#include <exception>
#include <string>

using namespace std;


class ExceptionStack : public exception {
 public:
  ExceptionStack(string msg);
  void push(string msg);
  virtual const char *what() const throw();
 private:
  vector<string> v;
};


#endif
