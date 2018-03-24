#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;


class Node {
    public:
        Node(int line);
        virtual void printAST(int tab = 0) = 0;
        int getLine();
    protected:
        void printOneNode(int tab, string name);
    private:
        int line;
};



class AProgram : public Node {
    public:
        AProgram(int line, Node *expList);
        void printAST(int tab);
    private:
        Node *expList;
};

class EmptyProgram : public Node {
    public:
        EmptyProgram(int line);
        void printAST(int tab);
};



class OneExpEL : public Node {
	public:
		OneExpEL(int line, Node *exp);
		void printAST(int tab);
	private:
		Node *exp;
};

class MulExpEL : public Node {
	public:
		MulExpEL(int line, Node *exp, Node *expList);
		void printAST(int tab);
	private:
		Node *exp;
		Node *expList;
};



class ScopeExp : public Node {
    public:
        ScopeExp(int line, Node *expList);
        void printAST(int tab);
    private:
        Node *expList;
};

class DefExp : public Node {
    public:
        DefExp(int line, string var);
        void printAST(int tab);
    private:
        string var;
};

class AssignExp : public Node {
    public:
        AssignExp(int line, string var, Node *exp);
        void printAST(int tab);
    private:
        string var;
        Node *exp;
};

class IfExp : public Node {
    public:
        IfExp(int line, Node *pred, Node *exp);
        void printAST(int tab);
    private:
        Node *pred;
        Node *exp;
};

class IfElseExp : public Node {
    public:
        IfElseExp(int line, Node *pred, Node *exp1, Node *exp2);
        void printAST(int tab);
    private:
        Node *pred;
        Node *exp1;
        Node *exp2;
};

class WhileExp : public Node {
    public:
        WhileExp(int line, Node *pred, Node *exp);
        void printAST(int tab);
    private:
        Node *pred;
        Node *exp;
};

class PrintExp : public Node {
	public:
		PrintExp(int line, Node *exp);
		void printAST(int tab);
	private:
		Node *exp;
};

class VarExp : public Node {
    public:
        VarExp(int line, string var);
        void printAST(int tab);
    private:
        string var;
};

class EmptyPL : public Node {
    public:
        EmptyPL(int line);
        void printAST(int tab);
};

class OneVarPL : public Node {
    public:
        OneVarPL(int line, string var);
        void printAST(int tab);
    private:
        string var;
};

class MulVarPL : public Node {
    public:
        MulVarPL(int line, string var, Node *nonEmptyPL);
        void printAST(int tab);
    private:
        string var;
        Node *nonEmptyPL;
};

class ProcExp : public Node {
    public:
        ProcExp(int line, Node *paramList, Node *expList);
        void printAST(int tab);
    private:
        Node *paramList;
        Node *expList;
};

class EmptyAL : public Node {
    public:
        EmptyAL(int line);
        void printAST(int tab);
};

class OneArgAL : public Node {
    public:
        OneArgAL(int line, Node *exp);
        void printAST(int tab);
    private:
        Node *exp;
};

class MulArgAL : public Node {
    public:
        MulArgAL(int line, Node *exp, Node *nonEmptyAL);
        void printAST(int tab);
    private:
        Node *exp;
        Node *nonEmptyAL;
};

class CallExp : public Node {
    public:
        CallExp(int line, Node *exp, Node *argList);
        void printAST(int tab);
    private:
        Node *exp;
        Node *argList;
};








class IntExp : public Node {
    public:
        IntExp(int line, int n);
        void printAST(int tab);
    private:
        int n;
};

class BoolExp : public Node {
    public:
        BoolExp(int line, bool b);
        void printAST(int tab);
    private:
        bool b;
};

class StringExp : public Node {
    public:
        StringExp(int line, string s);
        void printAST(int tab);
    private:
        string s;
};

class CharExp : public Node {
    public:
        CharExp(int line, char c);
        void printAST(int tab);
    private:
        char c;
};



#endif
