#include <node.h>

#include <iostream>

using namespace std;


Node::Node(int line) {
    this->line = line;
}

int Node::getLine() {
    return line;
}

void Node::printOneNode(int tab, string name) {
    for (int i=0; i<tab; i++) cout << "|  ";
    cout << name << endl;
}



AProgram::AProgram(int line, Node *expList) : Node::Node(line) {
    this->expList = expList;
}

void AProgram::printAST(int tab) {
    printOneNode(tab, "AProgram");
    expList->printAST(tab + 1);
}



EmptyProgram::EmptyProgram(int line) : Node::Node(line) {}

void EmptyProgram::printAST(int tab) {
    printOneNode(tab, "EmptyProgram");
}



OneExpEL::OneExpEL(int line, Node *exp) : Node::Node(line) {
	this->exp = exp;
}

void OneExpEL::printAST(int tab) {
	printOneNode(tab, "OneExpEL");
    exp->printAST(tab + 1);
}



MulExpEL::MulExpEL(int line, Node *exp, Node *expList) : Node::Node(line) {
	this->exp = exp;
	this->expList = expList;
}

void MulExpEL::printAST(int tab) {
	printOneNode(tab, "MulExpEL");
    exp->printAST(tab + 1);
	expList->printAST(tab + 1);
}



ScopeExp::ScopeExp(int line, Node *expList) : Node::Node(line) {
    this->expList = expList;
}

void ScopeExp::printAST(int tab) {
	printOneNode(tab, "ScopeExp");
	expList->printAST(tab + 1);
}



DefExp::DefExp(int line, string var) : Node::Node(line) {
    this->var = var;
}

void DefExp::printAST(int tab) {
	printOneNode(tab, "DefExp");
    printOneNode(tab + 1, "\"" + var + "\"");
}



AssignExp::AssignExp(int line, string var, Node *exp) : Node::Node(line) {
    this->var = var;
    this->exp = exp;
}

void AssignExp::printAST(int tab) {
	printOneNode(tab, "AssignExp");
    printOneNode(tab + 1, "\"" + var + "\"");
    exp->printAST(tab + 1);
}



IfExp::IfExp(int line, Node *pred, Node *exp) : Node::Node(line) {
    this->pred = pred;
    this->exp = exp;
}

void IfExp::printAST(int tab) {
	printOneNode(tab, "IfExp");
    pred->printAST(tab + 1);
    exp->printAST(tab + 1);
}



IfElseExp::IfElseExp(int line, Node *pred, Node *exp1, Node *exp2) : Node::Node(line) {
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



WhileExp::WhileExp(int line, Node *pred, Node *exp) : Node::Node(line) {
    this->pred = pred;
    this->exp = exp;
}

void WhileExp::printAST(int tab) {
	printOneNode(tab, "WhileExp");
    pred->printAST(tab + 1);
    exp->printAST(tab + 1);
}



PrintExp::PrintExp(int line, Node *exp) : Node::Node(line) {
	this->exp = exp;
}

void PrintExp::printAST(int tab) {
	printOneNode(tab, "PrintExp");
    exp->printAST(tab + 1);
}



VarExp::VarExp(int line, string var) : Node::Node(line) {
    this->var = var;
}

void VarExp::printAST(int tab) {
	printOneNode(tab, "VarExp");
    printOneNode(tab + 1, "\"" + var + "\"");
}



EmptyPL::EmptyPL(int line) : Node::Node(line) {}

void EmptyPL::printAST(int tab) {
    printOneNode(tab, "EmptyPL");
}



OneVarPL::OneVarPL(int line, string var) : Node::Node(line) {
    this->var = var;
}

void OneVarPL::printAST(int tab) {
    printOneNode(tab, "OneVarPL");
    printOneNode(tab + 1, "\"" + var + "\"");
}



MulVarPL::MulVarPL(int line, string var, Node *nonEmptyPL) : Node::Node(line) {
    this->var = var;
    this->nonEmptyPL = nonEmptyPL;
}

void MulVarPL::printAST(int tab) {
    printOneNode(tab, "MulVarPL");
    printOneNode(tab + 1, "\"" + var + "\"");
    nonEmptyPL->printAST(tab + 1);
}



ProcExp::ProcExp(int line, Node *paramList, Node *expList) : Node::Node(line) {
    this->paramList = paramList;
    this->expList = expList;
}

void ProcExp::printAST(int tab) {
    printOneNode(tab, "ProcExp");
    paramList->printAST(tab + 1);
    expList->printAST(tab + 1);
}



EmptyAL::EmptyAL(int line) : Node::Node(line) {}

void EmptyAL::printAST(int tab) {
    printOneNode(tab, "EmptyAL");
}



OneArgAL::OneArgAL(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void OneArgAL::printAST(int tab) {
    printOneNode(tab, "OneVarAL");
    exp->printAST(tab + 1);
}



MulArgAL::MulArgAL(int line, Node *exp, Node *nonEmptyAL) : Node::Node(line) {
    this->exp = exp;
    this->nonEmptyAL = nonEmptyAL;
}

void MulArgAL::printAST(int tab) {
    printOneNode(tab, "MulVarAL");
    exp->printAST(tab + 1);
    nonEmptyAL->printAST(tab + 1);
}



CallExp::CallExp(int line, Node *exp, Node *argList) : Node::Node(line) {
    this->exp = exp;
    this->argList = argList;
}

void CallExp::printAST(int tab) {
    printOneNode(tab, "CallExp");
    exp->printAST(tab + 1);
    argList->printAST(tab + 1);
}



ArrayConst::ArrayConst(int line, Node *itemList) : Node::Node(line) {
    this->itemList = itemList;
}

void ArrayConst::printAST(int tab) {
    printOneNode(tab, "ArrayConst");
    itemList->printAST(tab + 1);
}



OneExpIL::OneExpIL(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void OneExpIL::printAST(int tab) {
    printOneNode(tab, "OneExpIL");
    exp->printAST(tab + 1);
}



MulExpIL::MulExpIL(int line, Node *exp, Node *itemList) : Node::Node(line) {
    this->exp = exp;
    this->itemList = itemList;
}

void MulExpIL::printAST(int tab) {
    printOneNode(tab, "MulExpIL");
    exp->printAST(tab + 1);
    itemList->printAST(tab + 1);
}



ArrayExp::ArrayExp(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void ArrayExp::printAST(int tab) {
    printOneNode(tab, "ArrayExp");
    exp->printAST(tab + 1); 
}



ArrayGetExp::ArrayGetExp(int line, Node *exp1, Node *exp2) : Node::Node(line) {
    this->exp1 = exp1;
    this->exp2 = exp2;
}

void ArrayGetExp::printAST(int tab) {
    printOneNode(tab, "ArrayGetExp");
    exp1->printAST(tab + 1);
    exp2->printAST(tab + 1);
}



ArraySetExp::ArraySetExp(int line, Node *exp1, Node *exp2, Node *exp3) : Node::Node(line) {
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



SizeOfExp::SizeOfExp(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void SizeOfExp::printAST(int tab) {
    printOneNode(tab, "SizeOfExp");
    exp->printAST(tab + 1); 
}



BinOpExp::BinOpExp(int line, Node *exp1, Node *exp2) : Node::Node(line) {
    this->exp1 = exp1;
    this->exp2 = exp2;
}

void BinOpExp::printAST(int tab) {
    printOneNode(tab, "BinOpExp: " + opStr());
    exp1->printAST(tab + 1);
    exp2->printAST(tab + 1);
}



AddExp::AddExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *AddExp::calculate() {
    return nullptr; // TODO
}

string AddExp::opStr() {
    return "+";
}



SubExp::SubExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *SubExp::calculate() {
    return nullptr; // TODO
}

string SubExp::opStr() {
    return "-";
}



MulExp::MulExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *MulExp::calculate() {
    return nullptr; // TODO
}

string MulExp::opStr() {
    return "*";
}



DivExp::DivExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *DivExp::calculate() {
    return nullptr; // TODO
}

string DivExp::opStr() {
    return "/";
}



RemExp::RemExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *RemExp::calculate() {
    return nullptr; // TODO
}

string RemExp::opStr() {
    return "%";
}



EquExp::EquExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *EquExp::calculate() {
    return nullptr; // TODO
}

string EquExp::opStr() {
    return "==";
}



NEqExp::NEqExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *NEqExp::calculate() {
    return nullptr; // TODO
}

string NEqExp::opStr() {
    return "!=";
}



LoTExp::LoTExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *LoTExp::calculate() {
    return nullptr; // TODO
}

string LoTExp::opStr() {
    return "<";
}



GrTExp::GrTExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *GrTExp::calculate() {
    return nullptr; // TODO
}

string GrTExp::opStr() {
    return ">";
}



LEqExp::LEqExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *LEqExp::calculate() {
    return nullptr; // TODO
}

string LEqExp::opStr() {
    return "<=";
}



GEqExp::GEqExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *GEqExp::calculate() {
    return nullptr; // TODO
}

string GEqExp::opStr() {
    return ">=";
}



AndExp::AndExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *AndExp::calculate() {
    return nullptr; // TODO
}

string AndExp::opStr() {
    return "&";
}



OrExp::OrExp(int line, Node *exp1, Node *exp2) : BinOpExp::BinOpExp(line, exp1, exp2) {}

Value *OrExp::calculate() {
    return nullptr; // TODO
}

string OrExp::opStr() {
    return "|";
}



UnaOpExp::UnaOpExp(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void UnaOpExp::printAST(int tab) {
    printOneNode(tab, "UnaOpExp: " + opStr());
    exp->printAST(tab + 1);
}



MinExp::MinExp(int line, Node *exp) : UnaOpExp::UnaOpExp(line, exp) {}

Value *MinExp::calculate() {
    return nullptr; // TODO
}

string MinExp::opStr() {
    return "-";
}



NotExp::NotExp(int line, Node *exp) : UnaOpExp::UnaOpExp(line, exp) {}

Value *NotExp::calculate() {
    return nullptr; // TODO
}

string NotExp::opStr() {
    return "!";
}



ToStrExp::ToStrExp(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void ToStrExp::printAST(int tab) {
    printOneNode(tab, "ToStrExp");
    exp->printAST(tab + 1);
}



ToCharExp::ToCharExp(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void ToCharExp::printAST(int tab) {
    printOneNode(tab, "ToCharExp");
    exp->printAST(tab + 1);
}



ToIntExp::ToIntExp(int line, Node *exp) : Node::Node(line) {
    this->exp = exp;
}

void ToIntExp::printAST(int tab) {
    printOneNode(tab, "ToIntExp");
    exp->printAST(tab + 1);
}










IntExp::IntExp(int line, int n) : Node::Node(line) {
    this->n = n;
}

void IntExp::printAST(int tab) {
    printOneNode(tab, "IntExp");
    printOneNode(tab + 1, to_string(n));
}



BoolExp::BoolExp(int line, bool b) : Node::Node(line) {
    this->b = b;
}

void BoolExp::printAST(int tab) {
    printOneNode(tab, "BoolExp");
    printOneNode(tab + 1, (b ? "true" : "false"));
}



StringExp::StringExp(int line, string s) : Node::Node(line) {
    this->s = s;
}

void StringExp::printAST(int tab) {
    printOneNode(tab, "StringExp");
    printOneNode(tab + 1, "\"" + s + "\"");
}



CharExp::CharExp(int line, char c) : Node::Node(line) {
    this->c = c;
}

void CharExp::printAST(int tab) {
    printOneNode(tab, "CharExp");
    printOneNode(tab + 1, "'" + string(1, c) + "'");
}