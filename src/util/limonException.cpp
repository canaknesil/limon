#include <limonException.h>
#include <sstream>
#include <iostream>

using namespace std;


ExceptionStack::ExceptionStack(string msg)
{
  v = vector<string>();
  v.push_back(msg);
}

void ExceptionStack::push(string msg)
{
  v.push_back(msg);
}

const char *ExceptionStack::what() const throw()
{
  string str = "";
  int vec_size = v.size();
  for (int i = 0; i < vec_size; i++) {
    str += "[" + to_string(i+1) + "] " + v[i] + "\n";
  }

  size_t len = str.length();
  char *error_msg = new char[len + 1];
  str.copy(error_msg, len);
  return error_msg;
}
