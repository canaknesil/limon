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
    for (int i=0; i<tab; i++) cout << "  ";
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
    //exp->printAST(tab + 1);
}



MulExpEL::MulExpEL(int line, Node *exp, Node *expList) : Node::Node(line) {
	this->exp = exp;
	this->expList = expList;
}

void MulExpEL::printAST(int tab) {
	printOneNode(tab, "MulExpEL");
    //exp->printAST(tab + 1);
	//expList->printAST(tab + 1);
}