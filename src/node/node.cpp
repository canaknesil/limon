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








ConstExp::ConstExp(int line) : Node::Node(line) {}



IntConst::IntConst(int line, int n) : ConstExp::ConstExp(line) {
    this->n = n;
}

void IntConst::printAST(int tab) {
    printOneNode(tab, "IntConst");
    printOneNode(tab + 1, to_string(n));
}