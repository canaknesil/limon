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



ParamList::ParamList(int line, string var, ParamList *next) {
    this->line = line;
    this->var = var;
    this->next = next;
}

string ParamList::toString() {
    return "ParamList: " + toStringRec(this);
}

string ParamList::toStringRec(ParamList *pl) {
    return (pl == nullptr ? "" : pl->var + " " + toStringRec(pl->next));
}




ProcExp::ProcExp(int line, ParamList *paramList, Node *expList) : Node::Node(line) {
    this->paramList = paramList;
    this->expList = expList;
}

void ProcExp::printAST(int tab) {
    printOneNode(tab, "ProcExp");
    printOneNode(tab + 1, paramList->toString());
    expList->printAST(tab + 1);
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