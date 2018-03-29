#include <node.h>

#include <iostream>
#include <sstream>

using namespace std;


static string genExcStr(string s, int line) {
    stringstream ss;
    ss << "INTERPRETATION ERROR: Line " << line << ": " << s;
    return ss.str();
}



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

Value *AProgram::evaluate(Environment<Value *> *e) {
    return expList->evaluate(e);
}



EmptyProgram::EmptyProgram(string filename, int line) : Node::Node(filename, line) {}

EmptyProgram::~EmptyProgram() {}

void EmptyProgram::printAST(int tab) {
    printOneNode(tab, "EmptyProgram");
}

Node  *EmptyProgram::copy() {
    return new EmptyProgram(filename, line);
}

Value *EmptyProgram::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *OneExpEL::evaluate(Environment<Value *> *e) {
    return exp->evaluate(e);
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

Value *MulExpEL::evaluate(Environment<Value *> *e) {
    exp->evaluate(e);
    return expList->evaluate(e);
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

Value *ScopeExp::evaluate(Environment<Value *> *e) {
    return expList->evaluate(new Environment<Value *>(e));
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

Value *DefExp::evaluate(Environment<Value *> *e) {
    try {
        e->extend(var, nullptr);
    } catch (EnvException &exc) {
        throw NodeException(genExcStr(exc.what(), line));
    }
    return nullptr;
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

Value *AssignExp::evaluate(Environment<Value *> *e) {
    Value *val = exp->evaluate(e);
    try {
        e->set(var, val);
    } catch (EnvException &exc) {
        throw NodeException(genExcStr(exc.what(), line));
    }
    return nullptr;
}



IfExp::IfExp(string filename, int line, Node *pred, Node *exp) : Node::Node(filename, line) {
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

Value *IfExp::evaluate(Environment<Value *> *e) {
    Value *val = pred->evaluate(e);
    if (! VALUE_TYPE(val, BoolVal)) {
        throw NodeException(genExcStr("If expression predicate is not a Boolean value", line));
    }
    if (((BoolVal *) val)->getCBool()) {
        return exp->evaluate(e);
    } else {
        return nullptr;
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

Value *IfElseExp::evaluate(Environment<Value *> *e) {
    Value *val = pred->evaluate(e);
    if (! VALUE_TYPE(val, BoolVal)) {
        throw NodeException(genExcStr("If-Else expression predicate is not a Boolean value", line));
    }
    if (((BoolVal *) val)->getCBool()) {
        return exp1->evaluate(e);
    } else {
        return exp2->evaluate(e);
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

Value *WhileExp::evaluate(Environment<Value *> *e) {
    Value *last = nullptr;
    while (true) {
        Value *val = pred->evaluate(e);
        if (! VALUE_TYPE(val, BoolVal)) {
            throw NodeException(genExcStr("While expression predicate is not a Boolean value", line));
        }
        if (!(((BoolVal *) val)->getCBool())) return last;
        else last = exp->evaluate(e);
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

Value *PrintExp::evaluate(Environment<Value *> *e) {
    Value *val = exp->evaluate(e);
    if (!val) {
        cout << NULL_VAL_STR;
    } else {
        cout << val->toString();
    }
    return val;
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

Value *VarExp::evaluate(Environment<Value *> *e) {
    Value *val = nullptr;
    try {
        val = e->apply(var);
    } catch (EnvException &exc) {
        throw NodeException(genExcStr(exc.what(), line));
    }
    return val;
}



EmptyPL::EmptyPL(string filename, int line) : Node::Node(filename, line) {}

EmptyPL::~EmptyPL() {}

void EmptyPL::printAST(int tab) {
    printOneNode(tab, "EmptyPL");
}

Node  *EmptyPL::copy() {
    return new EmptyPL(filename, line);
}

Value *EmptyPL::evaluate(Environment<Value *> *e) {
    return nullptr;
}



OneVarPL::OneVarPL(string filename, int line, string var) : Node::Node(filename, line) {
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

Value *OneVarPL::evaluate(Environment<Value *> *e) {
    return nullptr;
}



MulVarPL::MulVarPL(string filename, int line, string var, Node *nonEmptyPL) : Node::Node(filename, line) {
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

Value *MulVarPL::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ProcExp::evaluate(Environment<Value *> *e) {
    return nullptr;
}



EmptyAL::EmptyAL(string filename, int line) : Node::Node(filename, line) {}

EmptyAL::~EmptyAL() {}

void EmptyAL::printAST(int tab) {
    printOneNode(tab, "EmptyAL");
}

Node  *EmptyAL::copy() {
    return new EmptyAL(filename, line);
}

Value *EmptyAL::evaluate(Environment<Value *> *e) {
    return nullptr;
}



OneArgAL::OneArgAL(string filename, int line, Node *exp) : Node::Node(filename, line) {
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

Value *OneArgAL::evaluate(Environment<Value *> *e) {
    return nullptr;
}



MulArgAL::MulArgAL(string filename, int line, Node *exp, Node *nonEmptyAL) : Node::Node(filename, line) {
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

Value *MulArgAL::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *CallExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ArrayConst::evaluate(Environment<Value *> *e) {
    return nullptr;
}



OneExpIL::OneExpIL(string filename, int line, Node *exp) : Node::Node(filename, line) {
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

Value *OneExpIL::evaluate(Environment<Value *> *e) {
    return nullptr;
}



MulExpIL::MulExpIL(string filename, int line, Node *exp, Node *itemList) : Node::Node(filename, line) {
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

Value *MulExpIL::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ArrayExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ArrayGetExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ArraySetExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *SizeOfExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *BinOpExp::evaluate(Environment<Value *> *e) {
    Value *v1 = exp1->evaluate(e);
    Value *v2 = exp2->evaluate(e);
    return calculate(v1, v2);
}



AddExp::AddExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

#define OP_VAL_TYPE(V1, T1, V2, T2) (VALUE_TYPE(V1, T1) && VALUE_TYPE(V2, T2))

Value *AddExp::calculate(Value *v1, Value *v2) {
    
    if (OP_VAL_TYPE(v1, IntVal, v2, IntVal)) return ((IntVal *) v1)->add((IntVal *) v2);
    
    else if (OP_VAL_TYPE(v1, StrVal, v2, IntVal)) return ((StrVal *) v1)->concat(((IntVal *) v2)->toString());
    else if (OP_VAL_TYPE(v2, StrVal, v1, IntVal)) return ((StrVal *) v2)->concatInv(((IntVal *) v1)->toString());
    
    else if (OP_VAL_TYPE(v1, CharVal, v2, IntVal)) return ((CharVal *) v1)->add(((IntVal *) v2)->getCLong());
    else if (OP_VAL_TYPE(v2, CharVal, v1, IntVal)) return ((CharVal *) v2)->add(((IntVal *) v1)->getCLong());

    else if (OP_VAL_TYPE(v1, StrVal, v2, BoolVal)) return ((StrVal *) v1)->concat(((BoolVal *) v2)->toString());
    else if (OP_VAL_TYPE(v2, StrVal, v1, BoolVal)) return ((StrVal *) v2)->concatInv(((BoolVal *) v1)->toString());

    else if (OP_VAL_TYPE(v1, CharVal, v2, BoolVal)) return new StrVal(string(((CharVal *) v1)->toString()) + ((BoolVal *) v1)->toString());
    else if (OP_VAL_TYPE(v2, CharVal, v1, BoolVal)) return new StrVal(string(((CharVal *) v2)->toString()) + ((BoolVal *) v1)->toString());

    else if (OP_VAL_TYPE(v1, StrVal, v2, StrVal)) return ((StrVal *) v1)->concat((StrVal *) v2);

    else if (OP_VAL_TYPE(v1, StrVal, v2, CharVal)) return ((StrVal *) v1)->concat(((CharVal *) v2)->toString());
    else if (OP_VAL_TYPE(v2, StrVal, v1, CharVal)) return ((StrVal *) v2)->concatInv(((CharVal *) v1)->toString());

    else if (OP_VAL_TYPE(v1, CharVal, v2, CharVal)) return new StrVal(string(((CharVal *) v1)->toString()) + ((CharVal *) v1)->toString());
    
    else {
        stringstream ss;
        ss << "Addition operation is not defined for types \"" << v1->getType() << " + " << v2->getType() << "\"";
        throw NodeException(genExcStr(ss.str(), line));
    }
}

string AddExp::opStr() {
    return "+";
}

Node *AddExp::copy() {
    return new AddExp(filename, line, exp1->copy(), exp2->copy());
}



SubExp::SubExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *SubExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string SubExp::opStr() {
    return "-";
}

Node *SubExp::copy() {
    return new SubExp(filename, line, exp1->copy(), exp2->copy());
}



MulExp::MulExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *MulExp::calculate(Value *v1, Value *v2) {
    if (OP_VAL_TYPE(v1, IntVal, v2, IntVal))
        return ((IntVal *) v1)->mul((IntVal *) v2);
    else {
        stringstream ss;
        ss << "Multiplication operation is not defined for types \"" << v1->getType() << " + " << v2->getType() << "\"";
        throw NodeException(genExcStr(ss.str(), line));
    }
}

string MulExp::opStr() {
    return "*";
}

Node *MulExp::copy() {
    return new MulExp(filename, line, exp1->copy(), exp2->copy());
}



DivExp::DivExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *DivExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string DivExp::opStr() {
    return "/";
}

Node *DivExp::copy() {
    return new DivExp(filename, line, exp1->copy(), exp2->copy());
}



RemExp::RemExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *RemExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string RemExp::opStr() {
    return "%";
}

Node *RemExp::copy() {
    return new RemExp(filename, line, exp1->copy(), exp2->copy());
}



EquExp::EquExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *EquExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string EquExp::opStr() {
    return "==";
}

Node *EquExp::copy() {
    return new EquExp(filename, line, exp1->copy(), exp2->copy());
}



NEqExp::NEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *NEqExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string NEqExp::opStr() {
    return "!=";
}

Node *NEqExp::copy() {
    return new NEqExp(filename, line, exp1->copy(), exp2->copy());
}



LoTExp::LoTExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *LoTExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string LoTExp::opStr() {
    return "<";
}

Node *LoTExp::copy() {
    return new LoTExp(filename, line, exp1->copy(), exp2->copy());
}



GrTExp::GrTExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *GrTExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string GrTExp::opStr() {
    return ">";
}

Node *GrTExp::copy() {
    return new GrTExp(filename, line, exp1->copy(), exp2->copy());
}



LEqExp::LEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *LEqExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string LEqExp::opStr() {
    return "<=";
}

Node *LEqExp::copy() {
    return new LEqExp(filename, line, exp1->copy(), exp2->copy());
}



GEqExp::GEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *GEqExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string GEqExp::opStr() {
    return ">=";
}

Node *GEqExp::copy() {
    return new GEqExp(filename, line, exp1->copy(), exp2->copy());
}



AndExp::AndExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *AndExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
}

string AndExp::opStr() {
    return "&";
}

Node *AndExp::copy() {
    return new AndExp(filename, line, exp1->copy(), exp2->copy());
}



OrExp::OrExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *OrExp::calculate(Value *v1, Value *v2) {
    return nullptr; // TODO
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

Value *UnaOpExp::evaluate(Environment<Value *> *e) {
    return nullptr;
}



MinExp::MinExp(string filename, int line, Node *exp) : UnaOpExp::UnaOpExp(filename, line, exp) {}

Value *MinExp::calculate() {
    return nullptr; // TODO
}

string MinExp::opStr() {
    return "-";
}

Node *MinExp::copy() {
    return new MinExp(filename, line, exp->copy());
}



NotExp::NotExp(string filename, int line, Node *exp) : UnaOpExp::UnaOpExp(filename, line, exp) {}

Value *NotExp::calculate() {
    return nullptr; // TODO
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

Value *ToStrExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ToCharExp::evaluate(Environment<Value *> *e) {
    return nullptr;
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

Value *ToIntExp::evaluate(Environment<Value *> *e) {
    return nullptr;
}




IntExp::IntExp(string filename, int line, string s) : Node::Node(filename, line) {
    this->s = s;
}

IntExp::~IntExp() {}

void IntExp::printAST(int tab) {
    printOneNode(tab, "IntExp");
    printOneNode(tab + 1, s);
}

Node  *IntExp::copy() {
    return new IntExp(filename, line, s);
}

Value *IntExp::evaluate(Environment<Value *> *e) {
    return new IntVal(s);
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

Value *BoolExp::evaluate(Environment<Value *> *e) {
    return new BoolVal(b);
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

Value *StringExp::evaluate(Environment<Value *> *e) {
    return new StrVal(s);
}



CharExp::CharExp(string filename, int line, char c) : Node::Node(filename, line) {
    this->c = c;
}

CharExp::~CharExp() {}

void CharExp::printAST(int tab) {
    printOneNode(tab, "CharExp");
    printOneNode(tab + 1, "'" + string(1, c) + "'");
}

Node  *CharExp::copy() {
    return new CharExp(filename, line, c);
}

Value *CharExp::evaluate(Environment<Value *> *e) {
    return new CharVal(c);
}
