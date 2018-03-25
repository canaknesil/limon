#ifndef NODE_H
#define NODE_H

#include <value.h>

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

class ArrayConst : public Node {
    public:
        ArrayConst(int line, Node *itemList);
        void printAST(int tab);
    private:
        Node *itemList;
};

class OneExpIL : public Node {
    public:
        OneExpIL(int line, Node *exp);
        void printAST(int tab);
    private:
        Node *exp;
};

class MulExpIL : public Node {
    public:
        MulExpIL(int line, Node *exp, Node *itemList);
        void printAST(int tab);
    private:
        Node *exp;
        Node *itemList;
};

class ArrayExp : public Node {
    public:
        ArrayExp(int line, Node *exp);
        void printAST(int tab);
    private:
        Node *exp;
};

class ArrayGetExp : public Node {
    public:
        ArrayGetExp(int line, Node *exp1, Node *exp2);
        void printAST(int tab);
    private:
        Node *exp1;
        Node *exp2;
};

class ArraySetExp : public Node {
    public:
        ArraySetExp(int line, Node *exp1, Node *exp2, Node *exp3);
        void printAST(int tab);
    private:
        Node *exp1;
        Node *exp2;
        Node *exp3;
};

class SizeOfExp : public Node {
    public:
        SizeOfExp(int line, Node *exp);
        void printAST(int tab);
    private:
        Node *exp;
};

class BinOpExp : public Node {
    public:
        BinOpExp(int line, Node *exp1, Node *exp2);
        void printAST(int tab);
    protected:
        virtual Value *calculate() = 0;
        virtual string opStr() = 0;
        Node *exp1;
        Node *exp2;
};

class AddExp : public BinOpExp {
    public:
        AddExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class SubExp : public BinOpExp {
    public:
        SubExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class MulExp : public BinOpExp {
    public:
        MulExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class DivExp : public BinOpExp {
    public:
        DivExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class RemExp : public BinOpExp {
    public:
        RemExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class EquExp : public BinOpExp {
    public:
        EquExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class NEqExp : public BinOpExp {
    public:
        NEqExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class LoTExp : public BinOpExp {
    public:
        LoTExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class GrTExp : public BinOpExp {
    public:
        GrTExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class LEqExp : public BinOpExp {
    public:
        LEqExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class GEqExp : public BinOpExp {
    public:
        GEqExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class AndExp : public BinOpExp {
    public:
        AndExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class OrExp : public BinOpExp {
    public:
        OrExp(int line, Node *exp1, Node *exp2);
    protected:
        Value *calculate();
        string opStr();
};

class UnaOpExp : public Node {
    public:
        UnaOpExp(int line, Node *exp);
        void printAST(int tab);
    protected:
        virtual Value *calculate() = 0;
        virtual string opStr() = 0;
        Node *exp;
};

class MinExp : public UnaOpExp {
    public:
        MinExp(int line, Node *exp);
    protected:
        Value *calculate();
        string opStr();
};

class NotExp : public UnaOpExp {
    public:
        NotExp(int line, Node *exp);
    protected:
        Value *calculate();
        string opStr();
};

class ToStrExp : public Node {
    public:
        ToStrExp(int line, Node* exp);
        void printAST(int tab);
    private:
        Node *exp;
};

class ToCharExp : public Node {
    public:
        ToCharExp(int line, Node* exp);
        void printAST(int tab);
    private:
        Node *exp;
};

class ToIntExp : public Node {
    public:
        ToIntExp(int line, Node* exp);
        void printAST(int tab);
    private:
        Node *exp;
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
