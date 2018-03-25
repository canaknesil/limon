#include <node.h>

#include <iostream>

using namespace std;


Node::Node(string filename, int line) {
    this->line = line;
    this->filename = filename;
}

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

void AProgram::printAST(int tab) {
    printOneNode(tab, "AProgram");
    expList->printAST(tab + 1);
}

Node  *AProgram::copy() {
    return new AProgram(filename, line, expList->copy());
}



EmptyProgram::EmptyProgram(string filename, int line) : Node::Node(filename, line) {}

void EmptyProgram::printAST(int tab) {
    printOneNode(tab, "EmptyProgram");
}

Node  *EmptyProgram::copy() {
    return new EmptyProgram(filename, line);
}



OneExpEL::OneExpEL(string filename, int line, Node *exp) : Node::Node(filename, line) {
	this->exp = exp;
}

void OneExpEL::printAST(int tab) {
	printOneNode(tab, "OneExpEL");
    exp->printAST(tab + 1);
}

Node  *OneExpEL::copy() {
    return new OneExpEL(filename, line, exp->copy());
}



MulExpEL::MulExpEL(string filename, int line, Node *exp, Node *expList) : Node::Node(filename, line) {
	this->exp = exp;
	this->expList = expList;
}

void MulExpEL::printAST(int tab) {
	printOneNode(tab, "MulExpEL");
    exp->printAST(tab + 1);
	expList->printAST(tab + 1);
}

Node  *MulExpEL::copy() {
    return new MulExpEL(filename, line, exp->copy(), expList->copy());
}



ScopeExp::ScopeExp(string filename, int line, Node *expList) : Node::Node(filename, line) {
    this->expList = expList;
}

void ScopeExp::printAST(int tab) {
	printOneNode(tab, "ScopeExp");
	expList->printAST(tab + 1);
}

Node  *ScopeExp::copy() {
    return new ScopeExp(filename, line, expList->copy());
}



DefExp::DefExp(string filename, int line, string var) : Node::Node(filename, line) {
    this->var = var;
}

void DefExp::printAST(int tab) {
	printOneNode(tab, "DefExp");
    printOneNode(tab + 1, "\"" + var + "\"");
}

Node  *DefExp::copy() {
    return new DefExp(filename, line, var);
}



AssignExp::AssignExp(string filename, int line, string var, Node *exp) : Node::Node(filename, line) {
    this->var = var;
    this->exp = exp;
}

void AssignExp::printAST(int tab) {
	printOneNode(tab, "AssignExp");
    printOneNode(tab + 1, "\"" + var + "\"");
    exp->printAST(tab + 1);
}

Node  *AssignExp::copy() {
    return new AssignExp(filename, line, var, exp->copy());
}



IfExp::IfExp(string filename, int line, Node *pred, Node *exp) : Node::Node(filename, line) {
    this->pred = pred;
    this->exp = exp;
}

void IfExp::printAST(int tab) {
	printOneNode(tab, "IfExp");
    pred->printAST(tab + 1);
    exp->printAST(tab + 1);
}

Node  *IfExp::copy() {
    return new IfExp(filename, line, pred->copy(), exp->copy());
}



IfElseExp::IfElseExp(string filename, int line, Node *pred, Node *exp1, Node *exp2) : Node::Node(filename, line) {
    this->pred = pred;
    this->exp1 = exp1;
    this->exp2 = exp2;
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



WhileExp::WhileExp(string filename, int line, Node *pred, Node *exp) : Node::Node(filename, line) {
    this->pred = pred;
    this->exp = exp;
}

void WhileExp::printAST(int tab) {
	printOneNode(tab, "WhileExp");
    pred->printAST(tab + 1);
    exp->printAST(tab + 1);
}

Node  *WhileExp::copy() {
    return new WhileExp(filename, line, pred->copy(), exp->copy());
}



PrintExp::PrintExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
	this->exp = exp;
}

void PrintExp::printAST(int tab) {
	printOneNode(tab, "PrintExp");
    exp->printAST(tab + 1);
}

Node  *PrintExp::copy() {
    return new PrintExp(filename, line, exp->copy());
}



VarExp::VarExp(string filename, int line, string var) : Node::Node(filename, line) {
    this->var = var;
}

void VarExp::printAST(int tab) {
	printOneNode(tab, "VarExp");
    printOneNode(tab + 1, "\"" + var + "\"");
}

Node  *VarExp::copy() {
    return new VarExp(filename, line, var);
}



EmptyPL::EmptyPL(string filename, int line) : Node::Node(filename, line) {}

void EmptyPL::printAST(int tab) {
    printOneNode(tab, "EmptyPL");
}

Node  *EmptyPL::copy() {
    return new EmptyPL(filename, line);
}



OneVarPL::OneVarPL(string filename, int line, string var) : Node::Node(filename, line) {
    this->var = var;
}

void OneVarPL::printAST(int tab) {
    printOneNode(tab, "OneVarPL");
    printOneNode(tab + 1, "\"" + var + "\"");
}

Node  *OneVarPL::copy() {
    return new OneVarPL(filename, line, var);
}



MulVarPL::MulVarPL(string filename, int line, string var, Node *nonEmptyPL) : Node::Node(filename, line) {
    this->var = var;
    this->nonEmptyPL = nonEmptyPL;
}

void MulVarPL::printAST(int tab) {
    printOneNode(tab, "MulVarPL");
    printOneNode(tab + 1, "\"" + var + "\"");
    nonEmptyPL->printAST(tab + 1);
}

Node  *MulVarPL::copy() {
    return new MulVarPL(filename, line, var, nonEmptyPL->copy());
}



ProcExp::ProcExp(string filename, int line, Node *paramList, Node *expList) : Node::Node(filename, line) {
    this->paramList = paramList;
    this->expList = expList;
}

void ProcExp::printAST(int tab) {
    printOneNode(tab, "ProcExp");
    paramList->printAST(tab + 1);
    expList->printAST(tab + 1);
}

Node  *ProcExp::copy() {
    return new ProcExp(filename, line, paramList->copy(), expList->copy());
}



EmptyAL::EmptyAL(string filename, int line) : Node::Node(filename, line) {}

void EmptyAL::printAST(int tab) {
    printOneNode(tab, "EmptyAL");
}

Node  *EmptyAL::copy() {
    return new EmptyAL(filename, line);
}



OneArgAL::OneArgAL(string filename, int line, Node *exp) : Node::Node(filename, line) {
    this->exp = exp;
}

void OneArgAL::printAST(int tab) {
    printOneNode(tab, "OneVarAL");
    exp->printAST(tab + 1);
}

Node  *OneArgAL::copy() {
    return new OneArgAL(filename, line, exp->copy());
}



MulArgAL::MulArgAL(string filename, int line, Node *exp, Node *nonEmptyAL) : Node::Node(filename, line) {
    this->exp = exp;
    this->nonEmptyAL = nonEmptyAL;
}

void MulArgAL::printAST(int tab) {
    printOneNode(tab, "MulVarAL");
    exp->printAST(tab + 1);
    nonEmptyAL->printAST(tab + 1);
}

Node  *MulArgAL::copy() {
    return new MulArgAL(filename, line, exp->copy(), nonEmptyAL->copy());
}



CallExp::CallExp(string filename, int line, Node *exp, Node *argList) : Node::Node(filename, line) {
    this->exp = exp;
    this->argList = argList;
}

void CallExp::printAST(int tab) {
    printOneNode(tab, "CallExp");
    exp->printAST(tab + 1);
    argList->printAST(tab + 1);
}

Node  *CallExp::copy() {
    return new CallExp(filename, line, exp->copy(), argList->copy());
}



ArrayConst::ArrayConst(string filename, int line, Node *itemList) : Node::Node(filename, line) {
    this->itemList = itemList;
}

void ArrayConst::printAST(int tab) {
    printOneNode(tab, "ArrayConst");
    itemList->printAST(tab + 1);
}

Node  *ArrayConst::copy() {
    return new ArrayConst(filename, line, itemList->copy());
}



OneExpIL::OneExpIL(string filename, int line, Node *exp) : Node::Node(filename, line) {
    this->exp = exp;
}

void OneExpIL::printAST(int tab) {
    printOneNode(tab, "OneExpIL");
    exp->printAST(tab + 1);
}

Node  *OneExpIL::copy() {
    return new OneExpIL(filename, line, exp->copy());
}



MulExpIL::MulExpIL(string filename, int line, Node *exp, Node *itemList) : Node::Node(filename, line) {
    this->exp = exp;
    this->itemList = itemList;
}

void MulExpIL::printAST(int tab) {
    printOneNode(tab, "MulExpIL");
    exp->printAST(tab + 1);
    itemList->printAST(tab + 1);
}

Node  *MulExpIL::copy() {
    return new MulExpIL(filename, line, exp->copy(), itemList->copy());
}



ArrayExp::ArrayExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
    this->exp = exp;
}

void ArrayExp::printAST(int tab) {
    printOneNode(tab, "ArrayExp");
    exp->printAST(tab + 1); 
}

Node  *ArrayExp::copy() {
    return new ArrayExp(filename, line, exp->copy());
}



ArrayGetExp::ArrayGetExp(string filename, int line, Node *exp1, Node *exp2) : Node::Node(filename, line) {
    this->exp1 = exp1;
    this->exp2 = exp2;
}

void ArrayGetExp::printAST(int tab) {
    printOneNode(tab, "ArrayGetExp");
    exp1->printAST(tab + 1);
    exp2->printAST(tab + 1);
}

Node  *ArrayGetExp::copy() {
    return new ArrayGetExp(filename, line, exp1->copy(), exp2->copy());
}



ArraySetExp::ArraySetExp(string filename, int line, Node *exp1, Node *exp2, Node *exp3) : Node::Node(filename, line) {
    this->exp1 = exp1;
    this->exp2 = exp2;
    this->exp3 = exp3;
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



SizeOfExp::SizeOfExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
    this->exp = exp;
}

void SizeOfExp::printAST(int tab) {
    printOneNode(tab, "SizeOfExp");
    exp->printAST(tab + 1); 
}

Node  *SizeOfExp::copy() {
    return new SizeOfExp(filename, line, exp->copy());
}



BinOpExp::BinOpExp(string filename, int line, Node *exp1, Node *exp2) : Node::Node(filename, line) {
    this->exp1 = exp1;
    this->exp2 = exp2;
}

void BinOpExp::printAST(int tab) {
    printOneNode(tab, "BinOpExp: " + opStr());
    exp1->printAST(tab + 1);
    exp2->printAST(tab + 1);
}



AddExp::AddExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *AddExp::calculate() {
    return nullptr; // TODO
}

string AddExp::opStr() {
    return "+";
}

Node *AddExp::copy() {
    return new AddExp(filename, line, exp1->copy(), exp2->copy());
}



SubExp::SubExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *SubExp::calculate() {
    return nullptr; // TODO
}

string SubExp::opStr() {
    return "-";
}

Node *SubExp::copy() {
    return new SubExp(filename, line, exp1->copy(), exp2->copy());
}



MulExp::MulExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *MulExp::calculate() {
    return nullptr; // TODO
}

string MulExp::opStr() {
    return "*";
}

Node *MulExp::copy() {
    return new MulExp(filename, line, exp1->copy(), exp2->copy());
}



DivExp::DivExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *DivExp::calculate() {
    return nullptr; // TODO
}

string DivExp::opStr() {
    return "/";
}

Node *DivExp::copy() {
    return new DivExp(filename, line, exp1->copy(), exp2->copy());
}



RemExp::RemExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *RemExp::calculate() {
    return nullptr; // TODO
}

string RemExp::opStr() {
    return "%";
}

Node *RemExp::copy() {
    return new RemExp(filename, line, exp1->copy(), exp2->copy());
}



EquExp::EquExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *EquExp::calculate() {
    return nullptr; // TODO
}

string EquExp::opStr() {
    return "==";
}

Node *EquExp::copy() {
    return new EquExp(filename, line, exp1->copy(), exp2->copy());
}



NEqExp::NEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *NEqExp::calculate() {
    return nullptr; // TODO
}

string NEqExp::opStr() {
    return "!=";
}

Node *NEqExp::copy() {
    return new NEqExp(filename, line, exp1->copy(), exp2->copy());
}



LoTExp::LoTExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *LoTExp::calculate() {
    return nullptr; // TODO
}

string LoTExp::opStr() {
    return "<";
}

Node *LoTExp::copy() {
    return new LoTExp(filename, line, exp1->copy(), exp2->copy());
}



GrTExp::GrTExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *GrTExp::calculate() {
    return nullptr; // TODO
}

string GrTExp::opStr() {
    return ">";
}

Node *GrTExp::copy() {
    return new GrTExp(filename, line, exp1->copy(), exp2->copy());
}



LEqExp::LEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *LEqExp::calculate() {
    return nullptr; // TODO
}

string LEqExp::opStr() {
    return "<=";
}

Node *LEqExp::copy() {
    return new LEqExp(filename, line, exp1->copy(), exp2->copy());
}



GEqExp::GEqExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *GEqExp::calculate() {
    return nullptr; // TODO
}

string GEqExp::opStr() {
    return ">=";
}

Node *GEqExp::copy() {
    return new GEqExp(filename, line, exp1->copy(), exp2->copy());
}



AndExp::AndExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *AndExp::calculate() {
    return nullptr; // TODO
}

string AndExp::opStr() {
    return "&";
}

Node *AndExp::copy() {
    return new AndExp(filename, line, exp1->copy(), exp2->copy());
}



OrExp::OrExp(string filename, int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(filename, line, exp1, exp2) {}

Value *OrExp::calculate() {
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

void UnaOpExp::printAST(int tab) {
    printOneNode(tab, "UnaOpExp: " + opStr());
    exp->printAST(tab + 1);
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

void ToStrExp::printAST(int tab) {
    printOneNode(tab, "ToStrExp");
    exp->printAST(tab + 1);
}

Node  *ToStrExp::copy() {
    return new ToStrExp(filename, line, exp->copy());
}



ToCharExp::ToCharExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
    this->exp = exp;
}

void ToCharExp::printAST(int tab) {
    printOneNode(tab, "ToCharExp");
    exp->printAST(tab + 1);
}

Node  *ToCharExp::copy() {
    return new ToCharExp(filename, line, exp->copy());
}



ToIntExp::ToIntExp(string filename, int line, Node *exp) : Node::Node(filename, line) {
    this->exp = exp;
}

void ToIntExp::printAST(int tab) {
    printOneNode(tab, "ToIntExp");
    exp->printAST(tab + 1);
}

Node  *ToIntExp::copy() {
    return new ToIntExp(filename, line, exp->copy());
}




IntExp::IntExp(string filename, int line, int n) : Node::Node(filename, line) {
    this->n = n;
}

void IntExp::printAST(int tab) {
    printOneNode(tab, "IntExp");
    printOneNode(tab + 1, to_string(n));
}

Node  *IntExp::copy() {
    return new IntExp(filename, line, n);
}



BoolExp::BoolExp(string filename, int line, bool b) : Node::Node(filename, line) {
    this->b = b;
}

void BoolExp::printAST(int tab) {
    printOneNode(tab, "BoolExp");
    printOneNode(tab + 1, (b ? "true" : "false"));
}

Node  *BoolExp::copy() {
    return new BoolExp(filename, line, b);
}



StringExp::StringExp(string filename, int line, string s) : Node::Node(filename, line) {
    this->s = s;
}

void StringExp::printAST(int tab) {
    printOneNode(tab, "StringExp");
    printOneNode(tab + 1, "\"" + s + "\"");
}

Node  *StringExp::copy() {
    return new StringExp(filename, line, s);
}



CharExp::CharExp(string filename, int line, char c) : Node::Node(filename, line) {
    this->c = c;
}

void CharExp::printAST(int tab) {
    printOneNode(tab, "CharExp");
    printOneNode(tab + 1, "'" + string(1, c) + "'");
}

Node  *CharExp::copy() {
    return new CharExp(filename, line, c);
}