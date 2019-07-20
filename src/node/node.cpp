#include <node.h>
#include <runHandler.h>

#include <iostream>
#include <sstream>

using namespace std;



Node::Node(string filename, int line) {
  this->line = line;
  this->filename = filename;
}

Node::~Node() {}

int Node::getLine() {
  return line;
}

string Node::getFilename() {
  return filename;
}

void Node::printOneNode(int tab, string name) {
  for (int i=0; i<tab; i++) cout << "|  ";
  cout << name << endl;
}



AProgram::AProgram(string filename, int line, Node *expList) : Node::Node(filename, line) {
  this->expList = expList;
}

AProgram::~AProgram() {
  delete expList;
}

void AProgram::printAST(int tab) {
  printOneNode(tab, "AProgram");
  expList->printAST(tab + 1);
}

Node  *AProgram::copy() {
  return new AProgram(filename, line, expList->copy());
}

Value *AProgram::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return expList->evaluate(gc, e);
}



EmptyProgram::EmptyProgram(string filename, int line) : Node::Node(filename, line) {}

EmptyProgram::~EmptyProgram() {}

void EmptyProgram::printAST(int tab) {
  printOneNode(tab, "EmptyProgram");
}

Node  *EmptyProgram::copy() {
  return new EmptyProgram(filename, line);
}

Value *EmptyProgram::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new NullVal(gc);
}



OneExpEL::OneExpEL(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

OneExpEL::~OneExpEL() {
  delete exp;
}

void OneExpEL::printAST(int tab) {
  printOneNode(tab, "OneExpEL");
  exp->printAST(tab + 1);
}

Node  *OneExpEL::copy() {
  return new OneExpEL(filename, line, exp->copy());
}

Value *OneExpEL::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return exp->evaluate(gc, e);
}



MulExpEL::MulExpEL(string filename, int line, Node *exp, Node *expList) : Node::Node(filename, line) {
  this->exp = exp;
  this->expList = expList;
}

MulExpEL::~MulExpEL() {
  delete exp;
  delete expList;
}

void MulExpEL::printAST(int tab) {
  printOneNode(tab, "MulExpEL");
  exp->printAST(tab + 1);
  expList->printAST(tab + 1);
}

Node  *MulExpEL::copy() {
  return new MulExpEL(filename, line, exp->copy(), expList->copy());
}

Value *MulExpEL::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  exp->evaluate(gc, e);
  return expList->evaluate(gc, e);
}



ScopeExp::ScopeExp(string filename, int line, Node *expList) : Node::Node(filename, line) {
  this->expList = expList;
}

ScopeExp::~ScopeExp() {
  delete expList;
}

void ScopeExp::printAST(int tab) {
  printOneNode(tab, "ScopeExp");
  expList->printAST(tab + 1);
}

Node  *ScopeExp::copy() {
  return new ScopeExp(filename, line, expList->copy());
}

Value *ScopeExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return expList->evaluate(gc, new Environment<Value *>(gc, e));
}



DefExp::DefExp(string filename, int line, string var) : Node::Node(filename, line) {
  this->var = var;
}

DefExp::~DefExp() {}

void DefExp::printAST(int tab) {
  printOneNode(tab, "DefExp");
  printOneNode(tab + 1, "\"" + var + "\"");
}

Node  *DefExp::copy() {
  return new DefExp(filename, line, var);
}

Value *DefExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = new NullVal(gc);
  try {
    e->extend(var, val);
  } catch (EnvException &exc) {
    throw NodeException(filename, line, exc.what());
  }
  return val;
}



AssignExp::AssignExp(string filename, int line, string var, Node *exp) : Node::Node(filename, line) {
  this->var = var;
  this->exp = exp;
}

AssignExp::~AssignExp() {
  delete exp;
}

void AssignExp::printAST(int tab) {
  printOneNode(tab, "AssignExp");
  printOneNode(tab + 1, "\"" + var + "\"");
  exp->printAST(tab + 1);
}

Node  *AssignExp::copy() {
  return new AssignExp(filename, line, var, exp->copy());
}

Value *AssignExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  try {
    e->set(var, val);
  } catch (EnvException &exc) {
    throw NodeException(filename, line, exc.what());
  }
  return val;
}



/*IfExp::IfExp(string filename, int line, Node *pred, Node *exp) : Node::Node(filename, line) {
  this->pred = pred;
  this->exp = exp;
  }

  IfExp::~IfExp() {
  delete pred;
  delete exp;
  }

  void IfExp::printAST(int tab) {
  printOneNode(tab, "IfExp");
  pred->printAST(tab + 1);
  exp->printAST(tab + 1);
  }

  Node  *IfExp::copy() {
  return new IfExp(filename, line, pred->copy(), exp->copy());
  }

  Value *IfExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = pred->evaluate(gc, e);
  if (! VALUE_TYPE(val, BoolVal)) {
  throw NodeException(filename, line, "If-Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type);
  }
  if (((BoolVal *) val)->getCBool()) {
  return exp->evaluate(gc, e);
  } else {
  return new NullVal(gc);
  }
  }



  IfElseExp::IfElseExp(string filename, int line, Node *pred, Node *exp1, Node *exp2) : Node::Node(filename, line) {
  this->pred = pred;
  this->exp1 = exp1;
  this->exp2 = exp2;
  }

  IfElseExp::~IfElseExp() {
  delete pred;
  delete exp1;
  delete exp2;
  }

  void IfElseExp::printAST(int tab) {
  printOneNode(tab, "IfElseExp");
  pred->printAST(tab + 1);
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
  }

  Node  *IfElseExp::copy() {
  return new IfElseExp(filename, line, pred->copy(), exp1->copy(), exp2->copy());
  }

  Value *IfElseExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = pred->evaluate(gc, e);
  if (! VALUE_TYPE(val, BoolVal)) {
  throw NodeException(filename, line, "If-Else-Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type);
  }
  if (((BoolVal *) val)->getCBool()) {
  return exp1->evaluate(gc, e);
  } else {
  return exp2->evaluate(gc, e);
  }
  }*/



CondExp::CondExp(string filename, int line, Node *condList) : Node::Node(filename, line) {
  this->condList = condList;
}

CondExp::~CondExp() {
  delete condList;
}

void CondExp::printAST(int tab) {
  printOneNode(tab, "CondExp");
  condList->printAST(tab + 1);
}

Node  *CondExp::copy() {
  return new CondExp(filename, line, condList->copy());
}

Value *CondExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = condList->evaluate(gc, e);
  if (!val) return new NullVal(gc);
  else return val;
}



CondElseExp::CondElseExp(string filename, int line, Node *condList, Node *exp) : Node::Node(filename, line) {
  this->condList = condList;
  this->exp = exp;
}

CondElseExp::~CondElseExp() {
  delete condList;
  delete exp;
}

void CondElseExp::printAST(int tab) {
  printOneNode(tab, "CondElseExp");
  condList->printAST(tab + 1);
  exp->printAST(tab + 1);
}

Node  *CondElseExp::copy() {
  return new CondElseExp(filename, line, condList->copy(), exp->copy());
}

Value *CondElseExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = condList->evaluate(gc, e);
  if (!val) return exp->evaluate(gc, e);
  else return val;
}



OneCondCL::OneCondCL(string filename, int line, Node *pred, Node *exp) : Node::Node(filename, line) {
  this->pred = pred;
  this->exp = exp;
}

OneCondCL::~OneCondCL() {
  delete pred;
  delete exp;
}

void OneCondCL::printAST(int tab) {
  printOneNode(tab, "OneCondCL");
  pred->printAST(tab + 1);
  exp->printAST(tab + 1);
}

Node  *OneCondCL::copy() {
  return new OneCondCL(filename, line, pred->copy(), exp->copy());
}

Value *OneCondCL::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = pred->evaluate(gc, e);
  if (! VALUE_TYPE(val, BoolVal)) {
    throw NodeException(filename, line, "Cond-Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type);
  }
  if (((BoolVal *) val)->getCBool()) {
    return exp->evaluate(gc, e);
  } else {
    return nullptr;
  }
}



MulCondCL::MulCondCL(string filename, int line, Node *pred, Node *exp, Node *condList) : Node::Node(filename, line) {
  this->pred = pred;
  this->exp = exp;
  this->condList = condList;
}

MulCondCL::~MulCondCL() {
  delete pred;
  delete exp;
  delete condList;
}

void MulCondCL::printAST(int tab) {
  printOneNode(tab, "MulCondCL");
  pred->printAST(tab + 1);
  exp->printAST(tab + 1);
  condList->printAST(tab + 1);
}

Node  *MulCondCL::copy() {
  return new MulCondCL(filename, line, pred->copy(), exp->copy(), condList->copy());
}

Value *MulCondCL::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = pred->evaluate(gc, e);
  if (! VALUE_TYPE(val, BoolVal)) {
    throw NodeException(filename, line, "Cond-Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type);
  }
  if (((BoolVal *) val)->getCBool()) {
    return exp->evaluate(gc, e);
  } else {
    return condList->evaluate(gc, e);
  }
}



WhileExp::WhileExp(string filename, int line, Node *pred, Node *exp) : Node::Node(filename, line) {
  this->pred = pred;
  this->exp = exp;
}

WhileExp::~WhileExp() {
  delete pred;
  delete exp;
}

void WhileExp::printAST(int tab) {
  printOneNode(tab, "WhileExp");
  pred->printAST(tab + 1);
  exp->printAST(tab + 1);
}

Node  *WhileExp::copy() {
  return new WhileExp(filename, line, pred->copy(), exp->copy());
}

Value *WhileExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *last = new NullVal(gc);
  while (true) {
    Value *val = pred->evaluate(gc, e);
    if (! VALUE_TYPE(val, BoolVal)) {
      throw NodeException(filename, line, "While-Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type);
    }
    if (!(((BoolVal *) val)->getCBool())) return last;
    else last = exp->evaluate(gc, e);
  }
}



PrintExp::PrintExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

PrintExp::~PrintExp() {
  delete exp;
}

void PrintExp::printAST(int tab) {
  printOneNode(tab, "PrintExp");
  exp->printAST(tab + 1);
}

Node  *PrintExp::copy() {
  return new PrintExp(filename, line, exp->copy());
}

Value *PrintExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  cout << val->toString();
  return val;
}



ValtypeExp::ValtypeExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ValtypeExp::~ValtypeExp() {
  delete exp;
}

void ValtypeExp::printAST(int tab) {
  printOneNode(tab, "ValtypeExp");
  exp->printAST(tab + 1);
}

Node  *ValtypeExp::copy() {
  return new ValtypeExp(filename, line, exp->copy());
}

Value *ValtypeExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  return new SymbolVal(gc, val->getLimonType());
}



ErrorExp::ErrorExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ErrorExp::~ErrorExp() {
  delete exp;
}

void ErrorExp::printAST(int tab) {
  printOneNode(tab, "ErrorExp");
  exp->printAST(tab + 1);
}

Node  *ErrorExp::copy() {
  return new ErrorExp(filename, line, exp->copy());
}

Value *ErrorExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  string error_str = val->toString();
  throw NodeException(filename, line, error_str);
  return val;
}



ScanExp::ScanExp(string filename, int line) : Node::Node(filename, line) {}

ScanExp::~ScanExp() {}

void ScanExp::printAST(int tab) {
  printOneNode(tab, "ScanExp");
}

Node  *ScanExp::copy() {
  return new ScanExp(filename, line);
}

Value *ScanExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  string str;
  cin >> str;
  if (cin.eof()) str = "";
  return new StrVal(gc, str);
}



VarExp::VarExp(string filename, int line, string var) : Node::Node(filename, line) {
  this->var = var;
}

VarExp::~VarExp() {}

void VarExp::printAST(int tab) {
  printOneNode(tab, "VarExp");
  printOneNode(tab + 1, "\"" + var + "\"");
}

Node  *VarExp::copy() {
  return new VarExp(filename, line, var);
}

Value *VarExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = nullptr;
  try {
    val = e->apply(var);
  } catch (EnvException &exc) {
    throw NodeException(filename, line, exc.what());
  }
  return val;
}



ParamList::ParamList(string filename, int line) : Node::Node(filename, line) {}

ParamList::~ParamList() {}

Value *ParamList::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return nullptr;
}



EmptyPL::EmptyPL(string filename, int line) : ParamList::ParamList(filename, line) {}

EmptyPL::~EmptyPL() {}

void EmptyPL::printAST(int tab) {
  printOneNode(tab, "EmptyPL");
}

Node  *EmptyPL::copy() {
  return new EmptyPL(filename, line);
}

vector<string> EmptyPL::getParamList() {
  return vector<string>();
}



OneVarPL::OneVarPL(string filename, int line, string var) : ParamList::ParamList(filename, line) {
  this->var = var;
}

OneVarPL::~OneVarPL() {}

void OneVarPL::printAST(int tab) {
  printOneNode(tab, "OneVarPL");
  printOneNode(tab + 1, "\"" + var + "\"");
}

Node  *OneVarPL::copy() {
  return new OneVarPL(filename, line, var);
}

vector<string> OneVarPL::getParamList() {
  vector<string> v = vector<string>();
  v.push_back(var);
  return v;
}



MulVarPL::MulVarPL(string filename, int line, string var, Node *nonEmptyPL) : ParamList::ParamList(filename, line) {
  this->var = var;
  this->nonEmptyPL = nonEmptyPL;
}

MulVarPL::~MulVarPL() {
  delete nonEmptyPL;
}

void MulVarPL::printAST(int tab) {
  printOneNode(tab, "MulVarPL");
  printOneNode(tab + 1, "\"" + var + "\"");
  nonEmptyPL->printAST(tab + 1);
}

Node  *MulVarPL::copy() {
  return new MulVarPL(filename, line, var, nonEmptyPL->copy());
}

vector<string> MulVarPL::getParamList() {
  vector<string> v = ((ParamList *) nonEmptyPL)->getParamList();
  v.push_back(var);
  return v;
}



ProcExp::ProcExp(string filename, int line, Node *paramList, Node *expList) : Node::Node(filename, line) {
  this->paramList = paramList;
  this->expList = expList;
}

ProcExp::~ProcExp() {
  delete paramList;
  delete expList;
}

void ProcExp::printAST(int tab) {
  printOneNode(tab, "ProcExp");
  paramList->printAST(tab + 1);
  expList->printAST(tab + 1);
}

Node  *ProcExp::copy() {
  return new ProcExp(filename, line, paramList->copy(), expList->copy());
}

Value *ProcExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  vector<string> pl = ((ParamList *) paramList)->getParamList();
  string var;
  if (!checkPL(pl, var)) throw NodeException(filename, line, "Procedure-Expression duplicate parameter \"" + var + "\"");
  return new ProcVal<Node *, Environment<Value *> *>(gc, pl , expList->copy(), e);
}

bool ProcExp::checkPL(vector<string> pl, string &var) {
  size_t size = pl.size();
  for (size_t i=0; i<size; i++) {
    for (size_t j=i+1; j<size; j++) {
      if (pl[i].compare(pl[j]) == 0) {
	var = pl[i];
	return false;
      }
    }
  }
  return true;
}



ArgList::ArgList(string filename, int line) : Node::Node(filename, line) {}

ArgList::~ArgList() {}

Value *ArgList::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return nullptr;
}



EmptyAL::EmptyAL(string filename, int line) : ArgList::ArgList(filename, line) {}

EmptyAL::~EmptyAL() {}

void EmptyAL::printAST(int tab) {
  printOneNode(tab, "EmptyAL");
}

Node  *EmptyAL::copy() {
  return new EmptyAL(filename, line);
}

vector<Value *> EmptyAL::getArgList(GarbageCollector *gc, Environment<Value *> *e) {
  return vector<Value *>();
}



OneArgAL::OneArgAL(string filename, int line, Node *exp) : ArgList::ArgList(filename, line) {
  this->exp = exp;
}

OneArgAL::~OneArgAL() {
  delete exp;
}

void OneArgAL::printAST(int tab) {
  printOneNode(tab, "OneVarAL");
  exp->printAST(tab + 1);
}

Node  *OneArgAL::copy() {
  return new OneArgAL(filename, line, exp->copy());
}

vector<Value *> OneArgAL::getArgList(GarbageCollector *gc, Environment<Value *> *e) {
  vector<Value *> v = vector<Value *>();
  v.push_back(exp->evaluate(gc, e));
  return v;
}



MulArgAL::MulArgAL(string filename, int line, Node *exp, Node *nonEmptyAL) : ArgList::ArgList(filename, line) {
  this->exp = exp;
  this->nonEmptyAL = nonEmptyAL;
}

MulArgAL::~MulArgAL() {
  delete exp;
  delete nonEmptyAL;
}

void MulArgAL::printAST(int tab) {
  printOneNode(tab, "MulVarAL");
  exp->printAST(tab + 1);
  nonEmptyAL->printAST(tab + 1);
}

Node  *MulArgAL::copy() {
  return new MulArgAL(filename, line, exp->copy(), nonEmptyAL->copy());
}

vector<Value *> MulArgAL::getArgList(GarbageCollector *gc, Environment<Value *> *e) {
  vector<Value *> v = ((ArgList *) nonEmptyAL)->getArgList(gc, e);
  v.push_back(exp->evaluate(gc, e));
  return v;
}



CallExp::CallExp(string filename, int line, Node *exp, Node *argList) : Node::Node(filename, line) {
  this->exp = exp;
  this->argList = argList;
}

CallExp::~CallExp() {
  delete exp;
  delete argList;
}

void CallExp::printAST(int tab) {
  printOneNode(tab, "CallExp");
  exp->printAST(tab + 1);
  argList->printAST(tab + 1);
}

Node  *CallExp::copy() {
  return new CallExp(filename, line, exp->copy(), argList->copy());
}

Value *CallExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *proc = exp->evaluate(gc, e);
  if (!VALUE_TYPE(proc, ProcVal<Node * COMMA Environment<Value *> *>)) 
    throw NodeException(filename, line, "Procedure-Expression operator is a " + proc->getType() + " rather than " + ProcVal<Node *, Environment<Value *> *>::type);
  vector<Value *> args = ((ArgList *) argList)->getArgList(gc, e);
  return applyProcedure(gc, (ProcVal<Node *, Environment<Value *> *> *) proc, args);
}

Value *CallExp::applyProcedure(GarbageCollector *gc, ProcVal<Node *, Environment<Value *> *> *proc, vector<Value *> argList) {
  vector<string> paramList = proc->getParamList();
  if (paramList.size() != argList.size()) throw NodeException(filename, line, "Call-Expression argument number does not match");
  Environment<Value *> *snapEnv = proc->getEnv();
  Environment<Value *> *env = new Environment<Value *>(gc, snapEnv);
  for (size_t i=0; i<paramList.size(); i++) {
    try {
      env->extend(paramList[i], argList[i]);
    } catch (EnvException &exc) {
      throw NodeException(filename, line, exc.what());
    }
  }
  return proc->getBody()->evaluate(gc, env);
}



ArrayConst::ArrayConst(string filename, int line, Node *itemList) : Node::Node(filename, line) {
  this->itemList = itemList;
}

ArrayConst::~ArrayConst() {
  delete itemList;
}

void ArrayConst::printAST(int tab) {
  printOneNode(tab, "ArrayConst");
  itemList->printAST(tab + 1);
}

Node  *ArrayConst::copy() {
  return new ArrayConst(filename, line, itemList->copy());
}

Value *ArrayConst::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  vector<Value *> il = ((ItemList *) itemList)->getItemList(gc, e);
  return new ArrayVal(gc, il);
}



ItemList::ItemList(string filename, int line) : Node::Node(filename, line) {}

ItemList::~ItemList() {}

Value *ItemList::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return nullptr;
}



OneExpIL::OneExpIL(string filename, int line, Node *exp) : ItemList::ItemList(filename, line) {
  this->exp = exp;
}

OneExpIL::~OneExpIL() {
  delete exp;
}

void OneExpIL::printAST(int tab) {
  printOneNode(tab, "OneExpIL");
  exp->printAST(tab + 1);
}

Node  *OneExpIL::copy() {
  return new OneExpIL(filename, line, exp->copy());
}

vector<Value *> OneExpIL::getItemList(GarbageCollector *gc, Environment<Value *> *e) {
  vector<Value *> v = vector<Value *>();
  v.push_back(exp->evaluate(gc, e));
  return v;
}



MulExpIL::MulExpIL(string filename, int line, Node *exp, Node *itemList) : ItemList::ItemList(filename, line) {
  this->exp = exp;
  this->itemList = itemList;
}

MulExpIL::~MulExpIL() {
  delete exp;
  delete itemList;
}

void MulExpIL::printAST(int tab) {
  printOneNode(tab, "MulExpIL");
  exp->printAST(tab + 1);
  itemList->printAST(tab + 1);
}

Node  *MulExpIL::copy() {
  return new MulExpIL(filename, line, exp->copy(), itemList->copy());
}

vector<Value *> MulExpIL::getItemList(GarbageCollector *gc, Environment<Value *> *e) {
  vector<Value *> v = ((ItemList *) itemList)->getItemList(gc, e);
  v.push_back(exp->evaluate(gc, e));
  return v;
}



ArrayExp::ArrayExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ArrayExp::~ArrayExp() {
  delete exp;
}

void ArrayExp::printAST(int tab) {
  printOneNode(tab, "ArrayExp");
  exp->printAST(tab + 1); 
}

Node  *ArrayExp::copy() {
  return new ArrayExp(filename, line, exp->copy());
}

Value *ArrayExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *v = exp->evaluate(gc, e);
  if (!VALUE_TYPE(v, IntVal)) throw NodeException(filename, line, "Array-Expression size is a " + v->getType() + " rather than " + IntVal::type);
  long n = ((IntVal *) v)->getCLong();
  if (n <= 0) throw NodeException(filename, line, "Array-Expression size must be a positive integer");
  Value *val;
  try {
    val = new ArrayVal(gc, ((IntVal *) v)->getCLong());
  } catch (ValueException &exc) {
    throw NodeException(filename, line, exc.what());
  }
  return val;
}



ArrayGetExp::ArrayGetExp(string filename, int line, Node *exp1, Node *exp2) : Node::Node(filename, line) {
  this->exp1 = exp1;
  this->exp2 = exp2;
}

ArrayGetExp::~ArrayGetExp() {
  delete exp1;
  delete exp2;
}

void ArrayGetExp::printAST(int tab) {
  printOneNode(tab, "ArrayGetExp");
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
}

Node  *ArrayGetExp::copy() {
  return new ArrayGetExp(filename, line, exp1->copy(), exp2->copy());
}

Value *ArrayGetExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val1 = exp1->evaluate(gc, e);
    
  if (VALUE_TYPE(val1, ArrayVal)) {

    Value *val2 = exp2->evaluate(gc, e);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw NodeException(filename, line, "Array-Get-Expression size is a " + val2->getType() + " rather than " + IntVal::type);
    long n = ((IntVal *) val2)->getCLong();

    try {
      return ((ArrayVal *) val1)->get(n);
    } catch (ValueException &exc) {
      throw NodeException(filename, line, exc.what());
    }

  } else if (VALUE_TYPE(val1, StrVal)) {

    Value *val2 = exp2->evaluate(gc, e);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw NodeException(filename, line, "String-Get-Expression size is a " + val2->getType() + " rather than " + IntVal::type);
    long n = ((IntVal *) val2)->getCLong();

    try {
      return new CharVal(gc, ((StrVal *) val1)->getCharAt(n));
    } catch (ValueException &exc) {
      throw NodeException(filename, line, exc.what());
    }

  } else throw NodeException(filename, line, "Array|String-Get-Expression is not defined for " + val1->getType());
}



ArraySetExp::ArraySetExp(string filename, int line, Node *exp1, Node *exp2, Node *exp3) : Node::Node(filename, line) {
  this->exp1 = exp1;
  this->exp2 = exp2;
  this->exp3 = exp3;
}

ArraySetExp::~ArraySetExp() {
  delete exp1;
  delete exp2;
  delete exp3;
}

void ArraySetExp::printAST(int tab) {
  printOneNode(tab, "ArraySetExp");
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
  exp3->printAST(tab + 1);
}

Node  *ArraySetExp::copy() {
  return new ArraySetExp(filename, line, exp1->copy(), exp2->copy(), exp3->copy());
}

Value *ArraySetExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val1 = exp1->evaluate(gc, e);
    
  if (VALUE_TYPE(val1, ArrayVal)) {

    Value *val2 = exp2->evaluate(gc, e);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw NodeException(filename, line, "Array-Set-Expression size is a " + val2->getType() + " rather than " + IntVal::type);
    long n = ((IntVal *) val2)->getCLong();

    Value *val3 = exp3->evaluate(gc, e);

    try {
      ((ArrayVal *) val1)->set(n, val3);
    } catch (ValueException &exc) {
      throw NodeException(filename, line, exc.what());
    }

  } else if (VALUE_TYPE(val1, StrVal)) {

    Value *val2 = exp2->evaluate(gc, e);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw NodeException(filename, line, "String-Set-Expression size is a " + val2->getType() + " rather than " + IntVal::type);
    long n = ((IntVal *) val2)->getCLong();

    Value *val3 = exp3->evaluate(gc, e);
    if (!VALUE_TYPE(val3, CharVal)) 
      throw NodeException(filename, line, "String-Set-Expression assigned value is a " + val3->getType() + " rather than " + CharVal::type);

    try {
      ((StrVal *) val1)->setCharAt(n, ((CharVal *) val3)->getCChar());
    } catch (ValueException &exc) {
      throw NodeException(filename, line, exc.what());
    }

  } else throw NodeException(filename, line, "Array|String-Set-Expression is not defined for " + val1->getType());

  return val1;
}



SizeOfExp::SizeOfExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

SizeOfExp::~SizeOfExp() {
  delete exp;
}

void SizeOfExp::printAST(int tab) {
  printOneNode(tab, "SizeOfExp");
  exp->printAST(tab + 1); 
}

Node  *SizeOfExp::copy() {
  return new SizeOfExp(filename, line, exp->copy());
}

Value *SizeOfExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  if (VALUE_TYPE(val, ArrayVal)) return new IntVal(gc, ((ArrayVal *) val)->getSize());
  else if (VALUE_TYPE(val, StrVal)) return new IntVal(gc, ((StrVal *) val)->getSize());
  else throw NodeException(filename, line, "Size-Of-Operation is not defined for type \"[sizeof " + val->getType() + "]\"");
}



BinOpExp::BinOpExp(string filename, int line, Node *exp1, Node *exp2) : Node::Node(filename, line) {
  this->exp1 = exp1;
  this->exp2 = exp2;
}

BinOpExp::~BinOpExp() {
  delete exp1;
  delete exp2;
}

void BinOpExp::printAST(int tab) {
  printOneNode(tab, "BinOpExp: " + opStr());
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
}

Value *BinOpExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *v1 = exp1->evaluate(gc, e);
  Value *v2 = exp2->evaluate(gc, e);
  return calculate(gc, v1, v2);
}



AddExp::AddExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

#define OP_VAL_TYPE(V1, T1, V2, T2) (VALUE_TYPE(V1, T1) && VALUE_TYPE(V2, T2))

Value *AddExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) 
{
  if (VALUE_TYPE(v1, StrVal)) return ((StrVal *) v1)->concat(v2->toString());
  else if (VALUE_TYPE(v2, StrVal)) return ((StrVal *) v2)->concatInv(v1->toString());

  else if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return ((IntVal *) v1)->add((IntVal *) v2);
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, IntVal)) return ((CharVal *) v1)->add(((IntVal *) v2)->getCLong());
  else if (OP_VAL_TYPE(v2, CharVal, v1, IntVal)) return ((CharVal *) v2)->add(((IntVal *) v1)->getCLong());

  else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new StrVal(gc, string(((CharVal *) v1)->toString()) + ((CharVal *) v2)->toString());

  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return ((FloatVal *) v1)->add((FloatVal *) v2);

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return ((FloatVal *) v1)->add(((IntVal *) v2)->getFloatVal());
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return ((FloatVal *) v2)->add(((IntVal *) v1)->getFloatVal());
    
  else throw NodeException(filename, line, "Addition-Operation is not defined for types \"" + v1->getType() + " + " + v2->getType() + "\"");
}

string AddExp::opStr() {
  return "+";
}

Node *AddExp::copy() {
  return new AddExp(filename, line, exp1->copy(), exp2->copy());
}



SubExp::SubExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *SubExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) 
{    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return ((IntVal *) v1)->sub((IntVal *) v2);
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, IntVal)) return ((CharVal *) v1)->add(-((IntVal *) v2)->getCLong());
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new IntVal(gc, ((CharVal *) v1)->sub((CharVal *) v2));

  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return ((FloatVal *)v1)->sub((FloatVal *) v2);

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return ((FloatVal *) v1)->sub(((IntVal *) v2)->getFloatVal());
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return ((IntVal *) v1)->getFloatVal()->sub((FloatVal *) v2);

  else throw NodeException(filename, line, "Substraction-Operation is not defined for types \"" + v1->getType() + " - " + v2->getType() + "\"");
}

string SubExp::opStr() {
  return "-";
}

Node *SubExp::copy() {
  return new SubExp(filename, line, exp1->copy(), exp2->copy());
}



MulExp::MulExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *MulExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return ((IntVal *) v1)->mul((IntVal *) v2);

  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return ((FloatVal *) v1)->mul((FloatVal *) v2);

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return ((FloatVal *) v1)->mul(((IntVal *) v2)->getFloatVal());
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return ((FloatVal *) v2)->mul(((IntVal *) v1)->getFloatVal());
    
  else throw NodeException(filename, line, "Multiplication-Operation is not defined for types \"" + v1->getType() + " * " + v2->getType() + "\"");
}

string MulExp::opStr() {
  return "*";
}

Node *MulExp::copy() {
  return new MulExp(filename, line, exp1->copy(), exp2->copy());
}



DivExp::DivExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *DivExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return ((IntVal *) v1)->div((IntVal *) v2);

  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return ((FloatVal *)v1)->div((FloatVal *) v2);

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return ((FloatVal *) v1)->div(((IntVal *) v2)->getFloatVal());
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return ((IntVal *) v1)->getFloatVal()->div((FloatVal *) v2);
    
  else throw NodeException(filename, line, "Division-Operation is not defined for types \"" + v1->getType() + " / " + v2->getType() + "\"");
}

string DivExp::opStr() {
  return "/";
}

Node *DivExp::copy() {
  return new DivExp(filename, line, exp1->copy(), exp2->copy());
}



RemExp::RemExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *RemExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return ((IntVal *) v1)->rem((IntVal *) v2);
  else throw NodeException(filename, line, "Remainder-Operation is not defined for types \"" + v1->getType() + " % " + v2->getType() + "\"");
}

string RemExp::opStr() {
  return "%";
}

Node *RemExp::copy() {
  return new RemExp(filename, line, exp1->copy(), exp2->copy());
}



EquExp::EquExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *EquExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
  if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return new BoolVal(gc, ((FloatVal *)v1)->equal(((IntVal *)v2)->getFloatVal()));
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return new BoolVal(gc, ((FloatVal *)v2)->equal(((IntVal *)v1)->getFloatVal()));
  else return new BoolVal(gc, v1->equal(v2));
}

string EquExp::opStr() {
  return "==";
}

Node *EquExp::copy() {
  return new EquExp(filename, line, exp1->copy(), exp2->copy());
}



NEqExp::NEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *NEqExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
  if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return new BoolVal(gc, !(((FloatVal *)v1)->equal(((IntVal *)v2)->getFloatVal())));
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return new BoolVal(gc, !(((FloatVal *)v2)->equal(((IntVal *)v1)->getFloatVal())));
  else return new BoolVal(gc, !(v1->equal(v2)));
}

string NEqExp::opStr() {
  return "!=";
}

Node *NEqExp::copy() {
  return new NEqExp(filename, line, exp1->copy(), exp2->copy());
}



LoTExp::LoTExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *LoTExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->lot((IntVal *) v2));
    
  else if (OP_VAL_TYPE(v1, StrVal, v2, StrVal)) return new BoolVal(gc, ((StrVal *) v1)->compare((StrVal *) v2) < 0);
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new BoolVal(gc, ((CharVal *) v1)->getCChar() < ((CharVal *) v2)->getCChar());
    
  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return new BoolVal(gc, ((FloatVal *)v1)->lot((FloatVal *) v2));

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return new BoolVal(gc, ((FloatVal *) v1)->lot(((IntVal *) v2)->getFloatVal()));
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->getFloatVal()->lot((FloatVal *) v2));

  else throw NodeException(filename, line, "Lower-Than-Operation is not defined for types \"" + v1->getType() + " < " + v2->getType() + "\"");
}

string LoTExp::opStr() {
  return "<";
}

Node *LoTExp::copy() {
  return new LoTExp(filename, line, exp1->copy(), exp2->copy());
}



GrTExp::GrTExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *GrTExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->grt((IntVal *) v2));
    
  else if (OP_VAL_TYPE(v1, StrVal, v2, StrVal)) return new BoolVal(gc, ((StrVal *) v1)->compare((StrVal *) v2) > 0);
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new BoolVal(gc, ((CharVal *) v1)->getCChar() > ((CharVal *) v2)->getCChar());
    
  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return new BoolVal(gc, ((FloatVal *)v1)->grt((FloatVal *) v2));

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return new BoolVal(gc, ((FloatVal *) v1)->grt(((IntVal *) v2)->getFloatVal()));
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->getFloatVal()->grt((FloatVal *) v2));

  else throw NodeException(filename, line, "Greater-Than-Operation is not defined for types \"" + v1->getType() + " > " + v2->getType() + "\"");
}

string GrTExp::opStr() {
  return ">";
}

Node *GrTExp::copy() {
  return new GrTExp(filename, line, exp1->copy(), exp2->copy());
}



LEqExp::LEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *LEqExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->leq((IntVal *) v2));
    
  else if (OP_VAL_TYPE(v1, StrVal, v2, StrVal)) return new BoolVal(gc, ((StrVal *) v1)->compare((StrVal *) v2) <= 0);
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new BoolVal(gc, ((CharVal *) v1)->getCChar() <= ((CharVal *) v2)->getCChar());
    
  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return new BoolVal(gc, ((FloatVal *)v1)->leq((FloatVal *) v2));

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return new BoolVal(gc, ((FloatVal *) v1)->leq(((IntVal *) v2)->getFloatVal()));
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->getFloatVal()->leq((FloatVal *) v2));

  else throw NodeException(filename, line, "Lower-Than-Or-Equal-Operation is not defined for types \"" + v1->getType() + " <= " + v2->getType() + "\"");
}

string LEqExp::opStr() {
  return "<=";
}

Node *LEqExp::copy() {
  return new LEqExp(filename, line, exp1->copy(), exp2->copy());
}



GEqExp::GEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *GEqExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
    
  if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->geq((IntVal *) v2));
    
  else if (OP_VAL_TYPE(v1, StrVal, v2, StrVal)) return new BoolVal(gc, ((StrVal *) v1)->compare((StrVal *) v2) >= 0);
    
  else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new BoolVal(gc, ((CharVal *) v1)->getCChar() >= ((CharVal *) v2)->getCChar());
    
  else if (OP_VAL_TYPE(v1, FloatVal, v2, FloatVal)) return new BoolVal(gc, ((FloatVal *)v1)->geq((FloatVal *) v2));

  else if (OP_VAL_TYPE(v1, FloatVal, v2, IntVal)) return new BoolVal(gc, ((FloatVal *) v1)->geq(((IntVal *) v2)->getFloatVal()));
  else if (OP_VAL_TYPE(v2, FloatVal, v1, IntVal)) return new BoolVal(gc, ((IntVal *) v1)->getFloatVal()->geq((FloatVal *) v2));

  else throw NodeException(filename, line, "Greater-Than-Or-Equal-Operation is not defined for types \"" + v1->getType() + " >= " + v2->getType() + "\"");
}

string GEqExp::opStr() {
  return ">=";
}

Node *GEqExp::copy() {
  return new GEqExp(filename, line, exp1->copy(), exp2->copy());
}



AndExp::AndExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *AndExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
  if (OP_VAL_TYPE(v1, BoolVal, v2, BoolVal)) {
    Value *val = ((BoolVal *) v1)->And((BoolVal *) v2);
    return val;
  }
  else throw NodeException(filename, line, "And-Operation is not defined for types \"" + v1->getType() + " & " + v2->getType() + "\"");
}

string AndExp::opStr() {
  return "&";
}

Node *AndExp::copy() {
  return new AndExp(filename, line, exp1->copy(), exp2->copy());
}



OrExp::OrExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *OrExp::calculate(GarbageCollector *gc, Value *v1, Value *v2) {
  if (OP_VAL_TYPE(v1, BoolVal, v2, BoolVal)) return ((BoolVal *) v1)->Or((BoolVal *) v2);
  else throw NodeException(filename, line, "Or-Operation is not defined for types \"" + v1->getType() + " | " + v2->getType() + "\"");
}

string OrExp::opStr() {
  return "|";
}

Node *OrExp::copy() {
  return new OrExp(filename, line, exp1->copy(), exp2->copy());
}



UnaOpExp::UnaOpExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

UnaOpExp::~UnaOpExp() {
  delete exp;
}

void UnaOpExp::printAST(int tab) {
  printOneNode(tab, "UnaOpExp: " + opStr());
  exp->printAST(tab + 1);
}

Value *UnaOpExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return calculate(gc, exp->evaluate(gc, e));
}



MinExp::MinExp(string filename, int line, Node *exp) : UnaOpExp::UnaOpExp(filename, line, exp) {}

Value *MinExp::calculate(GarbageCollector *gc, Value *v) {
  if (VALUE_TYPE(v, IntVal)) return ((IntVal *) v)->neg();
  else if (VALUE_TYPE(v, FloatVal)) return ((FloatVal *) v)->neg();
  else throw NodeException(filename, line, "Unary-Minus-Operation is not defined for type \"- " + v->getType() + "\"");
}

string MinExp::opStr() {
  return "-";
}

Node *MinExp::copy() {
  return new MinExp(filename, line, exp->copy());
}



NotExp::NotExp(string filename, int line, Node *exp) : UnaOpExp::UnaOpExp(filename, line, exp) {}

Value *NotExp::calculate(GarbageCollector *gc, Value *v) {
  if (VALUE_TYPE(v, BoolVal)) return ((BoolVal *) v)->Not();
  else throw NodeException(filename, line, "Not-Operation is not defined for type \"! " + v->getType() + "\"");
}

string NotExp::opStr() {
  return "!";
}

Node *NotExp::copy() {
  return new NotExp(filename, line, exp->copy());
}



ToStrExp::ToStrExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ToStrExp::~ToStrExp() {
  delete exp;
}

void ToStrExp::printAST(int tab) {
  printOneNode(tab, "ToStrExp");
  exp->printAST(tab + 1);
}

Node  *ToStrExp::copy() {
  return new ToStrExp(filename, line, exp->copy());
}

Value *ToStrExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new StrVal(gc, exp->evaluate(gc, e)->toString());
}



ToCharExp::ToCharExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ToCharExp::~ToCharExp() {
  delete exp;
}

void ToCharExp::printAST(int tab) {
  printOneNode(tab, "ToCharExp");
  exp->printAST(tab + 1);
}

Node  *ToCharExp::copy() {
  return new ToCharExp(filename, line, exp->copy());
}

Value *ToCharExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  if (VALUE_TYPE(val, IntVal)) return new CharVal(gc, ((IntVal *) val)->getCLong());
  else if (VALUE_TYPE(val, CharVal)) return val;
  else throw NodeException(filename, line, "To-Character-Operation is not defined for type \"[2char " + val->getType() + "]\"");
}



ToIntExp::ToIntExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ToIntExp::~ToIntExp() {
  delete exp;
}

void ToIntExp::printAST(int tab) {
  printOneNode(tab, "ToIntExp");
  exp->printAST(tab + 1);
}

Node  *ToIntExp::copy() {
  return new ToIntExp(filename, line, exp->copy());
}

Value *ToIntExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  if (VALUE_TYPE(val, IntVal)) return val;
  else if (VALUE_TYPE(val, CharVal)) return new IntVal(gc, ((CharVal *) val)->getCChar());
  else if (VALUE_TYPE(val, FloatVal)) return ((FloatVal *) val)->getIntVal(); 
  else throw NodeException(filename, line, "To-Integer-Operation is not defined for type \"[2int " + val->getType() + "]\"");
}



ToFloatExp::ToFloatExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

ToFloatExp::~ToFloatExp() {
  delete exp;
}

void ToFloatExp::printAST(int tab) {
  printOneNode(tab, "ToFloatExp");
  exp->printAST(tab + 1);
}

Node  *ToFloatExp::copy() {
  return new ToFloatExp(filename, line, exp->copy());
}

Value *ToFloatExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = exp->evaluate(gc, e);
  if (VALUE_TYPE(val, FloatVal)) return val;
  else if (VALUE_TYPE(val, IntVal)) return ((IntVal *) val)->getFloatVal();
  else throw NodeException(filename, line, "To-Float-Operation is not defined for type \"[2float " + val->getType() + "]\"");
}



RunExp::RunExp(string filename, int line, string fn) : Node::Node(filename, line) {
  this->fn = fn;
}

RunExp::~RunExp() {}

void RunExp::printAST(int tab) {
  printOneNode(tab, "RunExp");
}

Node  *RunExp::copy() {
  return new RunExp(filename, line, fn);
}

Value *RunExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  Value *val = RunHandler::interpretFile(fn, gc, e);
  if (!val) throw NodeException(filename, line, "Error while running file \"" + fn + "\"");
  return val;
}




IntExp::IntExp(string filename, int line, string s, int base) : Node::Node(filename, line) {
  this->s = s;
  this->base = base;
}

IntExp::~IntExp() {}

void IntExp::printAST(int tab) {
  printOneNode(tab, "IntExp (base=" + to_string(base) + ")");
  printOneNode(tab + 1, s);
}

Node  *IntExp::copy() {
  return new IntExp(filename, line, s, base);
}

Value *IntExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new IntVal(gc, s, base);
}



BoolExp::BoolExp(string filename, int line, bool b) : Node::Node(filename, line) {
  this->b = b;
}

BoolExp::~BoolExp() {}

void BoolExp::printAST(int tab) {
  printOneNode(tab, "BoolExp");
  printOneNode(tab + 1, (b ? "true" : "false"));
}

Node  *BoolExp::copy() {
  return new BoolExp(filename, line, b);
}

Value *BoolExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new BoolVal(gc, b);
}



StringExp::StringExp(string filename, int line, string s) : Node::Node(filename, line) {
  this->s = s;
}

StringExp::~StringExp() {}

void StringExp::printAST(int tab) {
  printOneNode(tab, "StringExp");
  printOneNode(tab + 1, "\"" + s + "\"");
}

Node  *StringExp::copy() {
  return new StringExp(filename, line, s);
}

Value *StringExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new StrVal(gc, s);
}



SymbolExp::SymbolExp(string filename, int line, string sym_str) : Node::Node(filename, line) {
  this->sym_str = sym_str;
}

SymbolExp::~SymbolExp() {}

void SymbolExp::printAST(int tab) {
  printOneNode(tab, "SymbolExp");
  printOneNode(tab + 1, ":" + sym_str);
}

Node  *SymbolExp::copy() {
  return new SymbolExp(filename, line, sym_str);
}

Value *SymbolExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new SymbolVal(gc, sym_str);
}



CharExp::CharExp(string filename, int line, char c) : Node::Node(filename, line) {
  this->c = c;
}

CharExp::~CharExp() {}

void CharExp::printAST(int tab) {
  printOneNode(tab, "CharExp");
  printOneNode(tab + 1, "'" + string(1, c) + "'");
}

Node *CharExp::copy() {
  return new CharExp(filename, line, c);
}

Value *CharExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new CharVal(gc, c);
}



FloatExp::FloatExp(string filename, int line, string f, int base, size_t prec) : Node::Node(filename, line) {
  this->f = f;
  this->base = base;
  this->prec = prec;
}

FloatExp::~FloatExp() {}

void FloatExp::printAST(int tab) {
  printOneNode(tab, "FloatExp (base=" + to_string(base) + ", precision=" + to_string(prec) + ")");
  printOneNode(tab + 1, f);
}

Node *FloatExp::copy() {
  return new FloatExp(filename, line, f, base, prec);
}

Value *FloatExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new FloatVal(gc, f, base, prec);
}



NullExp::NullExp(string filename, int line) : Node::Node(filename, line) {}

void NullExp::printAST(int tab) {
  printOneNode(tab, "NullExp");
}

Node *NullExp::copy() {
  return new NullExp(filename, line);
}

Value *NullExp::evaluate(GarbageCollector *gc, Environment<Value *> *e) {
  return new NullVal(gc);
}
