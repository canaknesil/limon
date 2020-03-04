#include <iostream>
#include <functionStack.h>

using namespace std;


int main() {

  FunctionStack *fs1 = new FunctionStack("main", "main.lmn", 5, nullptr);
  FunctionStack *fs2 = new FunctionStack("non_leaf_function", "test.lmn", 2,
					 fs1);
  FunctionStack *fs3 = new FunctionStack("leaf_function", "test.lmn", 4, fs2);

  cout << fs3->toString() << endl;

  delete fs3;

  return 0;
}
