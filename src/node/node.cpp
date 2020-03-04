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

string Node::evaluationErrorStr()
{
  return "Evaluation error in file \"" + filename + "\", at line "
    + to_string(line) + ".";
}

string Node::evaluationErrorStr(string msg)
{
  return "Evaluation error in file \"" + filename + "\", at line "
    + to_string(line) + ": " + msg;
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

Value *AProgram::evaluate(struct evaluationState state) {
  return expList->evaluate(state);
}



EmptyProgram::EmptyProgram(string filename, int line) : Node::Node(filename, line) {}

EmptyProgram::~EmptyProgram() {}

void EmptyProgram::printAST(int tab) {
  printOneNode(tab, "EmptyProgram");
}

Node  *EmptyProgram::copy() {
  return new EmptyProgram(filename, line);
}

Value *EmptyProgram::evaluate(struct evaluationState state) {
  return new NullVal(state.garbageCollector);
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

Value *OneExpEL::evaluate(struct evaluationState state) {
  return exp->evaluate(state);
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

Value *MulExpEL::evaluate(struct evaluationState state) {
  exp->evaluate(state);
  return expList->evaluate(state);
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

Value *ScopeExp::evaluate(struct evaluationState state) {
  Environment<Value *> *newEnvironment = new Environment<Value *>(state.garbageCollector, state.environment);
  state.environment = newEnvironment;
  return expList->evaluate(state);
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

Value *DefExp::evaluate(struct evaluationState state) {
  Value *val = new NullVal(state.garbageCollector);
  try {
    state.environment->extend(var, val);
  } catch (ExceptionStack &es) {
    es.push(evaluationErrorStr());
    throw es;
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

Value *AssignExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  try {
    state.environment->set(var, val);
  } catch (ExceptionStack &es) {
    es.push(evaluationErrorStr());
    throw es;
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

  Value *IfExp::evaluate(struct evaluationState state) {
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

  Value *IfElseExp::evaluate(struct evaluationState state) {
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

Value *CondExp::evaluate(struct evaluationState state) {
  Value *val = condList->evaluate(state);
  if (!val) return new NullVal(state.garbageCollector);
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

Value *CondElseExp::evaluate(struct evaluationState state) {
  Value *val = condList->evaluate(state);
  if (!val) return exp->evaluate(state);
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

Value *OneCondCL::evaluate(struct evaluationState state) {
  Value *val = pred->evaluate(state);
  if (! VALUE_TYPE(val, BoolVal)) {
    throw ExceptionStack(evaluationErrorStr("Condition Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type + "."));
  }
  if (((BoolVal *) val)->getCBool()) {
    return exp->evaluate(state);
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

Value *MulCondCL::evaluate(struct evaluationState state) {
  Value *val = pred->evaluate(state);
  if (! VALUE_TYPE(val, BoolVal)) {
    throw ExceptionStack(evaluationErrorStr("Condition Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type));
  }
  if (((BoolVal *) val)->getCBool()) {
    return exp->evaluate(state);
  } else {
    return condList->evaluate(state);
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

Value *WhileExp::evaluate(struct evaluationState state) {
  Value *last = new NullVal(state.garbageCollector);
  while (true) {
    Value *val = pred->evaluate(state);
    if (! VALUE_TYPE(val, BoolVal)) {
      throw ExceptionStack(evaluationErrorStr("While Expression predicate is a " + val->getType() + " rather than a " + BoolVal::type));
    }
    if (!(((BoolVal *) val)->getCBool())) return last;
    else last = exp->evaluate(state);
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

Value *PrintExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
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

Value *ValtypeExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  return new SymbolVal(state.garbageCollector, val->getLimonType());
}




GensymExp::GensymExp(string filename, int line) : Node::Node(filename, line) {
}

GensymExp::~GensymExp() {
}

void GensymExp::printAST(int tab) {
  printOneNode(tab, "GensymExp");
}

Node  *GensymExp::copy() {
  return new GensymExp(filename, line);
}

Value *GensymExp::evaluate(struct evaluationState state) {
  return new SymbolVal(state.garbageCollector);
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

Value *ErrorExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  string error_str = val->toString();
  throw ExceptionStack("Error generated in file \"" + filename + "\", at line " + to_string(line) + ": " + error_str);
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

Value *ScanExp::evaluate(struct evaluationState state) {
  string str;
  cin >> str;
  if (cin.eof()) str = "";
  return new StrVal(state.garbageCollector, str);
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

Value *VarExp::evaluate(struct evaluationState state) {
  Value *val = nullptr;
  try {
    val = state.environment->apply(var);
  } catch (ExceptionStack &es) {
    es.push(evaluationErrorStr());
    throw es;
  }
  return val;
}



ParamList::ParamList(string filename, int line) : Node::Node(filename, line) {}

ParamList::~ParamList() {}

Value *ParamList::evaluate(struct evaluationState state) {
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

Value *ProcExp::evaluate(struct evaluationState state) {
  vector<string> pl = ((ParamList *) paramList)->getParamList();
  string var;
  if (!checkPL(pl, var))
    throw ExceptionStack(evaluationErrorStr("Procedure Expression duplicate parameter \"" + var + "\""));
  return new ProcVal<Node *, Environment<Value *> *>(state.garbageCollector, pl , expList->copy(), state.environment);
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



// ArgList::ArgList(string filename, int line) : Node::Node(filename, line) {}

// ArgList::~ArgList() {}

// Value *ArgList::evaluate(struct evaluationState state) {
//   return nullptr;
// }



// EmptyAL::EmptyAL(string filename, int line) : ArgList::ArgList(filename, line) {}

// EmptyAL::~EmptyAL() {}

// void EmptyAL::printAST(int tab) {
//   printOneNode(tab, "EmptyAL");
// }

// Node  *EmptyAL::copy() {
//   return new EmptyAL(filename, line);
// }

// vector<Value *> EmptyAL::getArgList(struct evaluationState state) {
//   return vector<Value *>();
// }



// OneArgAL::OneArgAL(string filename, int line, Node *exp) : ArgList::ArgList(filename, line) {
//   this->exp = exp;
// }

// OneArgAL::~OneArgAL() {
//   delete exp;
// }

// void OneArgAL::printAST(int tab) {
//   printOneNode(tab, "OneVarAL");
//   exp->printAST(tab + 1);
// }

// Node  *OneArgAL::copy() {
//   return new OneArgAL(filename, line, exp->copy());
// }

// vector<Value *> OneArgAL::getArgList(struct evaluationState state) {
//   vector<Value *> v = vector<Value *>();
//   v.push_back(exp->evaluate(state));
//   return v;
// }



// MulArgAL::MulArgAL(string filename, int line, Node *exp, Node *nonEmptyAL) : ArgList::ArgList(filename, line) {
//   this->exp = exp;
//   this->nonEmptyAL = nonEmptyAL;
// }

// MulArgAL::~MulArgAL() {
//   delete exp;
//   delete nonEmptyAL;
// }

// void MulArgAL::printAST(int tab) {
//   printOneNode(tab, "MulVarAL");
//   exp->printAST(tab + 1);
//   nonEmptyAL->printAST(tab + 1);
// }

// Node  *MulArgAL::copy() {
//   return new MulArgAL(filename, line, exp->copy(), nonEmptyAL->copy());
// }

// vector<Value *> MulArgAL::getArgList(struct evaluationState state) {
//   vector<Value *> v = ((ArgList *) nonEmptyAL)->getArgList(state);
//   v.push_back(exp->evaluate(state));
//   return v;
// }



CallExp::CallExp(string filename, int line, Node *exp, Node *itemList) : Node::Node(filename, line) {
  this->exp = exp;
  this->itemList = itemList;
}

CallExp::~CallExp() {
  delete exp;
  delete itemList;
}

void CallExp::printAST(int tab) {
  printOneNode(tab, "CallExp");
  exp->printAST(tab + 1);
  itemList->printAST(tab + 1);
}

Node  *CallExp::copy() {
  return new CallExp(filename, line, exp->copy(), itemList->copy());
}

Value *CallExp::evaluate(struct evaluationState state) {
  Value *proc = exp->evaluate(state);
  if (!VALUE_TYPE(proc, ProcVal<Node * COMMA Environment<Value *> *>)) 
    throw ExceptionStack(evaluationErrorStr("Call Expression operator is a " + proc->getType() + " rather than " + ProcVal<Node *, Environment<Value *> *>::type));
  vector<Value *> args = ((ItemList *) itemList)->getItemList(state);

  stringstream stream;
  stream << (void *) proc;
  string proc_id = stream.str();
  state.functionStack->extend(proc_id, filename, line);

  Value *result = applyProcedure(state, (ProcVal<Node *, Environment<Value *> *> *) proc, args);

  state.functionStack->pop();

  return result;
}

Value *CallExp::applyProcedure(struct evaluationState state, ProcVal<Node *, Environment<Value *> *> *proc, vector<Value *> argList) {
  vector<string> paramList = proc->getParamList();
  if (paramList.size() != argList.size())
    throw ExceptionStack(evaluationErrorStr("Call Expression argument number does not match"));
  Environment<Value *> *snapEnv = proc->getEnv();
  Environment<Value *> *env = new Environment<Value *>(state.garbageCollector, snapEnv);
  for (size_t i=0; i<paramList.size(); i++) {
    try {
      env->extend(paramList[i], argList[i]);
    } catch (ExceptionStack &es) {
      es.push(evaluationErrorStr());
      throw es;
    }
  }

  state.environment = env;
  return proc->getBody()->evaluate(state);
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

Value *ArrayConst::evaluate(struct evaluationState state) {
  vector<Value *> il = ((ItemList *) itemList)->getItemList(state);
  return new ArrayVal(state.garbageCollector, il);
}



ItemList::ItemList(string filename, int line) : Node::Node(filename, line) {}

ItemList::~ItemList() {}

Value *ItemList::evaluate(struct evaluationState state) {
  return nullptr;
}



EmptyIL::EmptyIL(string filename, int line) : ItemList::ItemList(filename, line) {}

EmptyIL::~EmptyIL() {}

void EmptyIL::printAST(int tab) {
  printOneNode(tab, "EmptyIL");
}

Node  *EmptyIL::copy() {
  return new EmptyIL(filename, line);
}

vector<Value *> EmptyIL::getItemList(struct evaluationState state) {
  vector<Value *> v = vector<Value *>();
  return v;
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

vector<Value *> OneExpIL::getItemList(struct evaluationState state) {
  vector<Value *> v = vector<Value *>();
  v.push_back(exp->evaluate(state));
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

vector<Value *> MulExpIL::getItemList(struct evaluationState state) {
  vector<Value *> v = ((ItemList *) itemList)->getItemList(state);
  v.push_back(exp->evaluate(state));
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

Value *ArrayExp::evaluate(struct evaluationState state) {
  Value *v = exp->evaluate(state);
  if (!VALUE_TYPE(v, IntVal))
    throw ExceptionStack(evaluationErrorStr("Array Expression size is a " + v->getType() + " rather than " + IntVal::type));
  long n = ((IntVal *) v)->getCLong();
  if (n < 0)
    throw ExceptionStack(evaluationErrorStr("Array Expression size must be a positive integer"));
  Value *val;
  try {
    val = new ArrayVal(state.garbageCollector, ((IntVal *) v)->getCLong());
  } catch (ExceptionStack &es) {
    es.push(evaluationErrorStr());
    throw es;
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

Value *ArrayGetExp::evaluate(struct evaluationState state) {
  Value *val1 = exp1->evaluate(state);
    
  if (VALUE_TYPE(val1, ArrayVal)) {

    Value *val2 = exp2->evaluate(state);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw ExceptionStack(evaluationErrorStr("Array Get Expression index is a " + val2->getType() + " rather than " + IntVal::type));
    long n = ((IntVal *) val2)->getCLong();

    try {
      return ((ArrayVal *) val1)->get(n);
    } catch (ExceptionStack &es) {
      es.push(evaluationErrorStr()); throw es;
    }

  } else throw ExceptionStack(evaluationErrorStr("Array Get Expression is not defined for " + val1->getType()));
}




StrGetExp::StrGetExp(string filename, int line, Node *exp1, Node *exp2) : Node::Node(filename, line) {
  this->exp1 = exp1;
  this->exp2 = exp2;
}

StrGetExp::~StrGetExp() {
  delete exp1;
  delete exp2;
}

void StrGetExp::printAST(int tab) {
  printOneNode(tab, "StrGetExp");
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
}

Node  *StrGetExp::copy() {
  return new StrGetExp(filename, line, exp1->copy(), exp2->copy());
}

Value *StrGetExp::evaluate(struct evaluationState state) {
  Value *val1 = exp1->evaluate(state);
    
  if (VALUE_TYPE(val1, StrVal)) {

    Value *val2 = exp2->evaluate(state);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw ExceptionStack(evaluationErrorStr("String Get Expression index is a " + val2->getType() + " rather than " + IntVal::type));
    long n = ((IntVal *) val2)->getCLong();

    try {
      return new CharVal(state.garbageCollector, ((StrVal *) val1)->getCharAt(n));
    } catch (ExceptionStack &es) {
      es.push(evaluationErrorStr()); throw es;
    }

  } else throw ExceptionStack(evaluationErrorStr("String Get Expression is not defined for " + val1->getType()));
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

Value *ArraySetExp::evaluate(struct evaluationState state) {
  Value *val1 = exp1->evaluate(state);
    
  if (VALUE_TYPE(val1, ArrayVal)) {

    Value *val2 = exp2->evaluate(state);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw ExceptionStack(evaluationErrorStr("Array Set Expression index is a " + val2->getType() + " rather than " + IntVal::type));
    long n = ((IntVal *) val2)->getCLong();

    Value *val3 = exp3->evaluate(state);

    try {
      ((ArrayVal *) val1)->set(n, val3);
    } catch (ExceptionStack &es) {
      es.push(evaluationErrorStr()); throw es;
    }

  } else throw ExceptionStack(evaluationErrorStr("Array Set Expression is not defined for " + val1->getType()));

  return val1;
}





StrSetExp::StrSetExp(string filename, int line, Node *exp1, Node *exp2, Node *exp3) : Node::Node(filename, line) {
  this->exp1 = exp1;
  this->exp2 = exp2;
  this->exp3 = exp3;
}

StrSetExp::~StrSetExp() {
  delete exp1;
  delete exp2;
  delete exp3;
}

void StrSetExp::printAST(int tab) {
  printOneNode(tab, "StrSetExp");
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
  exp3->printAST(tab + 1);
}

Node  *StrSetExp::copy() {
  return new StrSetExp(filename, line, exp1->copy(), exp2->copy(), exp3->copy());
}

Value *StrSetExp::evaluate(struct evaluationState state) {
  Value *val1 = exp1->evaluate(state);
    
  if (VALUE_TYPE(val1, StrVal)) {

    Value *val2 = exp2->evaluate(state);
    if (!VALUE_TYPE(val2, IntVal)) 
      throw ExceptionStack(evaluationErrorStr("String Set Expression index is a " + val2->getType() + " rather than " + IntVal::type));
    long n = ((IntVal *) val2)->getCLong();

    Value *val3 = exp3->evaluate(state);
    if (!VALUE_TYPE(val3, CharVal)) 
      throw ExceptionStack(evaluationErrorStr("String Set Expression assigned value is a " + val3->getType() + " rather than " + CharVal::type));

    try {
      ((StrVal *) val1)->setCharAt(n, ((CharVal *) val3)->getCChar());
    } catch (ExceptionStack &es) {
      es.push(evaluationErrorStr()); throw es;
    }

  } else throw ExceptionStack(evaluationErrorStr("String Set Expression is not defined for " + val1->getType()));

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

Value *SizeOfExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  if (VALUE_TYPE(val, ArrayVal)) return new IntVal(state.garbageCollector, ((ArrayVal *) val)->getSize());
  else if (VALUE_TYPE(val, StrVal)) return new IntVal(state.garbageCollector, ((StrVal *) val)->getSize());
  else throw ExceptionStack(evaluationErrorStr("Sizeof Operation is not defined for type \"[sizeof " + val->getType() + "]\""));
}




SameExp::SameExp(string filename, int line, Node *exp1, Node *exp2) : Node::Node(filename, line) {
  this->exp1 = exp1;
  this->exp2 = exp2;
}

SameExp::~SameExp() {
  delete exp1;
  delete exp2;
}

void SameExp::printAST(int tab) {
  printOneNode(tab, "SameExp");
  exp1->printAST(tab + 1);
  exp2->printAST(tab + 1);
}

Node  *SameExp::copy() {
  return new SameExp(filename, line, exp1->copy(), exp2->copy());
}

Value *SameExp::evaluate(struct evaluationState state) {
  Value *val1 = exp1->evaluate(state);
  Value *val2 = exp2->evaluate(state);
  return new BoolVal(state.garbageCollector, val1 == val2);
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

Value *BinOpExp::evaluate(struct evaluationState state) {
  Value *v1 = exp1->evaluate(state);
  Value *v2 = exp2->evaluate(state);
  return calculate(state.garbageCollector, v1, v2);
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
    
  else throw ExceptionStack(evaluationErrorStr("Addition Operation is not defined for types \"" + v1->getType() + " + " + v2->getType() + "\""));
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

  else throw ExceptionStack(evaluationErrorStr("Substraction Operation is not defined for types \"" + v1->getType() + " - " + v2->getType() + "\""));
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
    
  else throw ExceptionStack(evaluationErrorStr("Multiplication Operation is not defined for types \"" + v1->getType() + " * " + v2->getType() + "\""));
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
    
  else throw ExceptionStack(evaluationErrorStr("Division Operation is not defined for types \"" + v1->getType() + " / " + v2->getType() + "\""));
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
  else throw ExceptionStack(evaluationErrorStr("Remainder Operation is not defined for types \"" + v1->getType() + " % " + v2->getType() + "\""));
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

  else throw ExceptionStack(evaluationErrorStr("Lower Than Operation is not defined for types \"" + v1->getType() + " < " + v2->getType() + "\""));
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

  else throw ExceptionStack(evaluationErrorStr("Greater Than Operation is not defined for types \"" + v1->getType() + " > " + v2->getType() + "\""));
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

  else throw ExceptionStack(evaluationErrorStr("Lower Than Or Equal Operation is not defined for types \"" + v1->getType() + " <= " + v2->getType() + "\""));
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

  else throw ExceptionStack(evaluationErrorStr("Greater Than Or Equal Operation is not defined for types \"" + v1->getType() + " >= " + v2->getType() + "\""));
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
  else throw ExceptionStack(evaluationErrorStr("And Operation is not defined for types \"" + v1->getType() + " & " + v2->getType() + "\""));
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
  else throw ExceptionStack(evaluationErrorStr("Or Operation is not defined for types \"" + v1->getType() + " | " + v2->getType() + "\""));
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

Value *UnaOpExp::evaluate(struct evaluationState state) {
  return calculate(state.garbageCollector, exp->evaluate(state));
}



MinExp::MinExp(string filename, int line, Node *exp) : UnaOpExp::UnaOpExp(filename, line, exp) {}

Value *MinExp::calculate(GarbageCollector *gc, Value *v) {
  if (VALUE_TYPE(v, IntVal)) return ((IntVal *) v)->neg();
  else if (VALUE_TYPE(v, FloatVal)) return ((FloatVal *) v)->neg();
  else throw ExceptionStack(evaluationErrorStr("Unary Minus Operation is not defined for type \"- " + v->getType() + "\""));
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
  else throw ExceptionStack(evaluationErrorStr("Not Operation is not defined for type \"! " + v->getType() + "\""));
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

Value *ToStrExp::evaluate(struct evaluationState state) {
  return new StrVal(state.garbageCollector, exp->evaluate(state)->toString());
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

Value *ToCharExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  if (VALUE_TYPE(val, IntVal)) return new CharVal(state.garbageCollector, ((IntVal *) val)->getCLong());
  else if (VALUE_TYPE(val, CharVal)) return val;
  else throw ExceptionStack(evaluationErrorStr("To Character Operation is not defined for type \"[2char " + val->getType() + "]\""));
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

Value *ToIntExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  if (VALUE_TYPE(val, IntVal)) return val;
  else if (VALUE_TYPE(val, CharVal)) return new IntVal(state.garbageCollector, ((CharVal *) val)->getCChar());
  else if (VALUE_TYPE(val, FloatVal)) return ((FloatVal *) val)->getIntVal(); 
  else throw ExceptionStack(evaluationErrorStr("To Integer Operation is not defined for type \"[2int " + val->getType() + "]\""));
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

Value *ToFloatExp::evaluate(struct evaluationState state) {
  Value *val = exp->evaluate(state);
  if (VALUE_TYPE(val, FloatVal)) return val;
  else if (VALUE_TYPE(val, IntVal)) return ((IntVal *) val)->getFloatVal();
  else throw ExceptionStack(evaluationErrorStr("To Float Operation is not defined for type \"[2float " + val->getType() + "]\""));
}



RunExp::RunExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
  this->exp = exp;
}

RunExp::~RunExp() {
  delete exp;
}

void RunExp::printAST(int tab) {
  printOneNode(tab, "RunExp");
  exp->printAST(tab + 1);
}

Node  *RunExp::copy() {
  return new RunExp(filename, line, exp->copy());
}

Value *RunExp::evaluate(struct evaluationState state) {
  Value *fnameVal = exp->evaluate(state);
  if (!VALUE_TYPE(fnameVal, StrVal))
    throw ExceptionStack(evaluationErrorStr("Run Expression filename is a " +
                                            fnameVal->getType() + " rather than a " +
                                            StrVal::type + "."));
  string fn = ((StrVal *) fnameVal)->toString();
  Value *val = nullptr;
  try {
    val = RunHandler::interpretFile(fn, state);
  } catch (ExceptionStack &es) {
    es.push(evaluationErrorStr("Error running file \"" + fn + "\"."));
    throw es;
  }
  if (!val) throw ExceptionStack(evaluationErrorStr("Error running file \"" + fn + "\"."));
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

Value *IntExp::evaluate(struct evaluationState state) {
  return new IntVal(state.garbageCollector, s, base);
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

Value *BoolExp::evaluate(struct evaluationState state) {
  return new BoolVal(state.garbageCollector, b);
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

Value *StringExp::evaluate(struct evaluationState state) {
  return new StrVal(state.garbageCollector, s);
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

Value *SymbolExp::evaluate(struct evaluationState state) {
  return new SymbolVal(state.garbageCollector, sym_str);
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

Value *CharExp::evaluate(struct evaluationState state) {
  return new CharVal(state.garbageCollector, c);
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

Value *FloatExp::evaluate(struct evaluationState state) {
  return new FloatVal(state.garbageCollector, f, base, prec);
}



NullExp::NullExp(string filename, int line) : Node::Node(filename, line) {}

void NullExp::printAST(int tab) {
  printOneNode(tab, "NullExp");
}

Node *NullExp::copy() {
  return new NullExp(filename, line);
}

Value *NullExp::evaluate(struct evaluationState state) {
  return new NullVal(state.garbageCollector);
}



