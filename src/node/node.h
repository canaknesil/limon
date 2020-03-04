#ifndef NODE_H
#define NODE_H

#include <value.h>
#include <environment.h>
#include <limonException.h>
#include <functionStack.h>
#include <evaluationState.h>

#include <string>

using namespace std;


class Node {
public:
  Node(string filename, int line);
  virtual ~Node();
  virtual void printAST(int tab = 0) = 0;
  virtual Node *copy() = 0;
  virtual Value *evaluate(struct evaluationState state) = 0;
  int getLine();
  string getFilename();
protected:
  void printOneNode(int tab, string name);
  string evaluationErrorStr();
  string evaluationErrorStr(string msg);
  int line;
  string filename;
};



class AProgram : public Node {
public:
  AProgram(string filename, int line, Node *expList);
  ~AProgram();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *expList;
};

class EmptyProgram : public Node {
public:
  EmptyProgram(string filename, int line);
  ~EmptyProgram();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
};



class OneExpEL : public Node {
public:
  OneExpEL(string filename, int line, Node *exp);
  ~OneExpEL();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class MulExpEL : public Node {
public:
  MulExpEL(string filename, int line, Node *exp, Node *expList);
  ~MulExpEL();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
  Node *expList;
};



class ScopeExp : public Node {
public:
  ScopeExp(string filename, int line, Node *expList);
  ~ScopeExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *expList;
};

class DefExp : public Node {
public:
  DefExp(string filename, int line, string var);
  ~DefExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string var;
};

class AssignExp : public Node {
public:
  AssignExp(string filename, int line, string var, Node *exp);
  ~AssignExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string var;
  Node *exp;
};

/*class IfExp : public Node {
  public:
  IfExp(string filename, int line, Node *pred, Node *exp);
  ~IfExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
  private:
  Node *pred;
  Node *exp;
  };

  class IfElseExp : public Node {
  public:
  IfElseExp(string filename, int line, Node *pred, Node *exp1, Node *exp2);
  ~IfElseExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
  private:
  Node *pred;
  Node *exp1;
  Node *exp2;
  };*/

class CondExp : public Node {
public:
  CondExp(string filename, int line, Node *condList);
  ~CondExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *condList;
};

class CondElseExp : public Node {
public:
  CondElseExp(string filename, int line, Node *condList, Node *exp);
  ~CondElseExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *condList;
  Node *exp;
};

class OneCondCL : public Node {
public:
  OneCondCL(string filename, int line, Node *pred, Node *exp);
  ~OneCondCL();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *pred;
  Node *exp;
};

class MulCondCL : public Node {
public:
  MulCondCL(string filename, int line, Node *pred, Node *exp, Node *condList);
  ~MulCondCL();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *pred;
  Node *exp;
  Node *condList;
};

class WhileExp : public Node {
public:
  WhileExp(string filename, int line, Node *pred, Node *exp);
  ~WhileExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *pred;
  Node *exp;
};

class PrintExp : public Node {
public:
  PrintExp(string filename, int line, Node *exp);
  ~PrintExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class ValtypeExp : public Node {
public:
  ValtypeExp(string filename, int line, Node *exp);
  ~ValtypeExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class GensymExp : public Node {
public:
  GensymExp(string filename, int line);
  ~GensymExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
};

class SameExp : public Node {
public:
  SameExp(string filename, int line, Node *exp1, Node *exp2);
  ~SameExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp1;
  Node *exp2;
};

class ErrorExp : public Node {
public:
  ErrorExp(string filename, int line, Node *exp);
  ~ErrorExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class ScanExp : public Node {
public:
  ScanExp(string filename, int line);
  ~ScanExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string var;
};

class VarExp : public Node {
public:
  VarExp(string filename, int line, string var);
  ~VarExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string var;
};

class ParamList : public Node {
public:
  ParamList(string filename, int line);
  virtual ~ParamList();
  virtual vector<string> getParamList() = 0;
  Value *evaluate(struct evaluationState state);
};

class EmptyPL : public ParamList {
public:
  EmptyPL(string filename, int line);
  ~EmptyPL();
  void printAST(int tab);
  Node *copy();
  vector<string> getParamList();
};

class OneVarPL : public ParamList {
public:
  OneVarPL(string filename, int line, string var);
  ~OneVarPL();
  void printAST(int tab);
  Node *copy();
  vector<string> getParamList();
private:
  string var;
};

class MulVarPL : public ParamList {
public:
  MulVarPL(string filename, int line, string var, Node *nonEmptyPL);
  ~MulVarPL();
  void printAST(int tab);
  Node *copy();
  vector<string> getParamList();
private:
  string var;
  Node *nonEmptyPL;
};

class ProcExp : public Node {
public:
  ProcExp(string filename, int line, Node *paramList, Node *expList);
  ~ProcExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *paramList;
  Node *expList;
  bool checkPL(vector<string> pl, string &var);
};

// class ArgList : public Node {
// public:
//   ArgList(string filename, int line);
//   virtual ~ArgList();
//   virtual vector<Value *> getArgList(struct evaluationState state) = 0;
//   Value *evaluate(struct evaluationState state);
// };

// class EmptyAL : public ArgList {
// public:
//   EmptyAL(string filename, int line);
//   ~EmptyAL();
//   void printAST(int tab);
//   Node *copy();
//   vector<Value *> getArgList(struct evaluationState state);
// };

// class OneArgAL : public ArgList {
// public:
//   OneArgAL(string filename, int line, Node *exp);
//   ~OneArgAL();
//   void printAST(int tab);
//   Node *copy();
//   vector<Value *> getArgList(struct evaluationState state);
// private:
//   Node *exp;
// };

// class MulArgAL : public ArgList {
// public:
//   MulArgAL(string filename, int line, Node *exp, Node *nonEmptyAL);
//   ~MulArgAL();
//   void printAST(int tab);
//   Node *copy();
//   vector<Value *> getArgList(struct evaluationState state);
// private:
//   Node *exp;
//   Node *nonEmptyAL;
// };

class CallExp : public Node {
public:
  CallExp(string filename, int line, Node *exp, Node *itemList);
  ~CallExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
  Node *itemList;
  Value *applyProcedure(struct evaluationState state, ProcVal<Node *, Environment<Value *> *> *proc, vector<Value *> argList);
};

class ArrayConst : public Node {
public:
  ArrayConst(string filename, int line, Node *itemList);
  ~ArrayConst();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *itemList;
};

class ItemList : public Node {
public:
  ItemList(string filename, int line);
  virtual ~ItemList();
  virtual vector<Value *> getItemList(struct evaluationState state) = 0;
  Value *evaluate(struct evaluationState state);
};

class EmptyIL : public ItemList {
public:
  EmptyIL(string filename, int line);
  ~EmptyIL();
  void printAST(int tab);
  Node *copy();
  vector<Value *> getItemList(struct evaluationState state);
};

class OneExpIL : public ItemList {
public:
  OneExpIL(string filename, int line, Node *exp);
  ~OneExpIL();
  void printAST(int tab);
  Node *copy();
  vector<Value *> getItemList(struct evaluationState state);
private:
  Node *exp;
};

class MulExpIL : public ItemList {
public:
  MulExpIL(string filename, int line, Node *exp, Node *itemList);
  ~MulExpIL();
  void printAST(int tab);
  Node *copy();
  vector<Value *> getItemList(struct evaluationState state);
private:
  Node *exp;
  Node *itemList;
};

class ArrayExp : public Node {
public:
  ArrayExp(string filename, int line, Node *exp);
  ~ArrayExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class ArrayGetExp : public Node {
public:
  ArrayGetExp(string filename, int line, Node *exp1, Node *exp2);
  ~ArrayGetExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp1;
  Node *exp2;
};

class StrGetExp : public Node {
public:
  StrGetExp(string filename, int line, Node *exp1, Node *exp2);
  ~StrGetExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp1;
  Node *exp2;
};

class ArraySetExp : public Node {
public:
  ArraySetExp(string filename, int line, Node *exp1, Node *exp2, Node *exp3);
  ~ArraySetExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp1;
  Node *exp2;
  Node *exp3;
};

class StrSetExp : public Node {
public:
  StrSetExp(string filename, int line, Node *exp1, Node *exp2, Node *exp3);
  ~StrSetExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp1;
  Node *exp2;
  Node *exp3;
};

class SizeOfExp : public Node {
public:
  SizeOfExp(string filename, int line, Node *exp);
  ~SizeOfExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class BinOpExp : public Node {
public:
  BinOpExp(string filename, int line, Node *exp1, Node *exp2);
  ~BinOpExp();
  void printAST(int tab);
  Value *evaluate(struct evaluationState state);
protected:
  virtual Value *calculate(GarbageCollector *gc, Value *v1, Value *v2) = 0;
  virtual string opStr() = 0;
  Node *exp1;
  Node *exp2;
};

class AddExp : public BinOpExp {
public:
  AddExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class SubExp : public BinOpExp {
public:
  SubExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class MulExp : public BinOpExp {
public:
  MulExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class DivExp : public BinOpExp {
public:
  DivExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class RemExp : public BinOpExp {
public:
  RemExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class EquExp : public BinOpExp {
public:
  EquExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class NEqExp : public BinOpExp {
public:
  NEqExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class LoTExp : public BinOpExp {
public:
  LoTExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class GrTExp : public BinOpExp {
public:
  GrTExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class LEqExp : public BinOpExp {
public:
  LEqExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class GEqExp : public BinOpExp {
public:
  GEqExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class AndExp : public BinOpExp {
public:
  AndExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class OrExp : public BinOpExp {
public:
  OrExp(string filename, int line, Node *exp1, Node *exp2);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v1, Value *v2);
  string opStr();
};

class UnaOpExp : public Node {
public:
  UnaOpExp(string filename, int line, Node *exp);
  ~UnaOpExp();
  void printAST(int tab);
  Value *evaluate(struct evaluationState state);
protected:
  virtual Value *calculate(GarbageCollector *gc, Value *v) = 0;
  virtual string opStr() = 0;
  Node *exp;
};

class MinExp : public UnaOpExp {
public:
  MinExp(string filename, int line, Node *exp);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v);
  string opStr();
};

class NotExp : public UnaOpExp {
public:
  NotExp(string filename, int line, Node *exp);
  Node *copy();
protected:
  Value *calculate(GarbageCollector *gc, Value *v);
  string opStr();
};

class ToStrExp : public Node {
public:
  ToStrExp(string filename, int line, Node* exp);
  ~ToStrExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class ToCharExp : public Node {
public:
  ToCharExp(string filename, int line, Node* exp);
  ~ToCharExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class ToIntExp : public Node {
public:
  ToIntExp(string filename, int line, Node* exp);
  ~ToIntExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};

class ToFloatExp : public Node {
public:
  ToFloatExp(string filename, int line, Node* exp);
  ~ToFloatExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};



class RunExp : public Node {
public:
  RunExp(string filename, int line, Node *exp);
  ~RunExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  Node *exp;
};



class IntExp : public Node {
public:
  IntExp(string filename, int line, string s, int base = 10);
  ~IntExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string s;
  int base;
};

class BoolExp : public Node {
public:
  BoolExp(string filename, int line, bool b);
  ~BoolExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  bool b;
};

class StringExp : public Node {
public:
  StringExp(string filename, int line, string s);
  ~StringExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string s;
};

class SymbolExp : public Node {
public:
  SymbolExp(string filename, int line, string sym_str);
  ~SymbolExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string sym_str;
};

class CharExp : public Node {
public:
  CharExp(string filename, int line, char c);
  ~CharExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  char c;
};

class FloatExp : public Node {
public:
  FloatExp(string filename, int line, string f, int base, size_t prec);
  ~FloatExp();
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
private:
  string f;
  int base;
  size_t prec;
};

class NullExp : public Node {
public:
  NullExp(string filaname, int line);
  void printAST(int tab);
  Node *copy();
  Value *evaluate(struct evaluationState state);
};



#endif
