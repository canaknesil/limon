#ifndef NODE_H
#define NODE_H

#include <value.h>

#include <string>

using namespace std;


class Node {
    public:
        Node(string filename, int line);
        virtual ~Node();
        virtual void printAST(int tab = 0) = 0;
        virtual Node *copy() = 0;
        int getLine();
        string getFilename();
    protected:
        void printOneNode(int tab, string name);
        int line;
        string filename;
};



class AProgram : public Node {
    public:
        AProgram(string filename, int line, Node *expList);
        ~AProgram();
        void printAST(int tab);
        Node *copy();
    private:
        Node *expList;
};

class EmptyProgram : public Node {
    public:
        EmptyProgram(string filename, int line);
        ~EmptyProgram();
        void printAST(int tab);
        Node *copy();
};



class OneExpEL : public Node {
	public:
		OneExpEL(string filename, int line, Node *exp);
        ~OneExpEL();
		void printAST(int tab);
        Node *copy();
	private:
		Node *exp;
};

class MulExpEL : public Node {
	public:
		MulExpEL(string filename, int line, Node *exp, Node *expList);
        ~MulExpEL();
		void printAST(int tab);
        Node *copy();
	private:
		Node *exp;
		Node *expList;
};



class ScopeExp : public Node {
    public:
        ScopeExp(string filename, int line, Node *expList);
        ~ScopeExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *expList;
};

class DefExp : public Node {
    public:
        DefExp(string filename, int line, string var);
        ~DefExp();
        void printAST(int tab);
        Node *copy();
    private:
        string var;
};

class AssignExp : public Node {
    public:
        AssignExp(string filename, int line, string var, Node *exp);
        ~AssignExp();
        void printAST(int tab);
        Node *copy();
    private:
        string var;
        Node *exp;
};

class IfExp : public Node {
    public:
        IfExp(string filename, int line, Node *pred, Node *exp);
        ~IfExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *pred;
        Node *exp;
};

class IfElseExp : public Node {
    public:
        IfElseExp(string filename, int line, Node *pred, Node *exp1, Node *exp2);
        ~IfElseExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *pred;
        Node *exp1;
        Node *exp2;
};

class WhileExp : public Node {
    public:
        WhileExp(string filename, int line, Node *pred, Node *exp);
        ~WhileExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *pred;
        Node *exp;
};

class PrintExp : public Node {
	public:
		PrintExp(string filename, int line, Node *exp);
        ~PrintExp();
		void printAST(int tab);
        Node *copy();
	private:
		Node *exp;
};

class VarExp : public Node {
    public:
        VarExp(string filename, int line, string var);
        ~VarExp();
        void printAST(int tab);
        Node *copy();
    private:
        string var;
};

class EmptyPL : public Node {
    public:
        EmptyPL(string filename, int line);
        ~EmptyPL();
        void printAST(int tab);
        Node *copy();
};

class OneVarPL : public Node {
    public:
        OneVarPL(string filename, int line, string var);
        ~OneVarPL();
        void printAST(int tab);
        Node *copy();
    private:
        string var;
};

class MulVarPL : public Node {
    public:
        MulVarPL(string filename, int line, string var, Node *nonEmptyPL);
        ~MulVarPL();
        void printAST(int tab);
        Node *copy();
    private:
        string var;
        Node *nonEmptyPL;
};

class ProcExp : public Node {
    public:
        ProcExp(string filename, int line, Node *paramList, Node *expList);
        ~ProcExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *paramList;
        Node *expList;
};

class EmptyAL : public Node {
    public:
        EmptyAL(string filename, int line);
        ~EmptyAL();
        void printAST(int tab);
        Node *copy();
};

class OneArgAL : public Node {
    public:
        OneArgAL(string filename, int line, Node *exp);
        ~OneArgAL();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};

class MulArgAL : public Node {
    public:
        MulArgAL(string filename, int line, Node *exp, Node *nonEmptyAL);
        ~MulArgAL();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
        Node *nonEmptyAL;
};

class CallExp : public Node {
    public:
        CallExp(string filename, int line, Node *exp, Node *argList);
        ~CallExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
        Node *argList;
};

class ArrayConst : public Node {
    public:
        ArrayConst(string filename, int line, Node *itemList);
        ~ArrayConst();
        void printAST(int tab);
        Node *copy();
    private:
        Node *itemList;
};

class OneExpIL : public Node {
    public:
        OneExpIL(string filename, int line, Node *exp);
        ~OneExpIL();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};

class MulExpIL : public Node {
    public:
        MulExpIL(string filename, int line, Node *exp, Node *itemList);
        ~MulExpIL();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
        Node *itemList;
};

class ArrayExp : public Node {
    public:
        ArrayExp(string filename, int line, Node *exp);
        ~ArrayExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};

class ArrayGetExp : public Node {
    public:
        ArrayGetExp(string filename, int line, Node *exp1, Node *exp2);
        ~ArrayGetExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp1;
        Node *exp2;
};

class ArraySetExp : public Node {
    public:
        ArraySetExp(string filename, int line, Node *exp1, Node *exp2, Node *exp3);
        ~ArraySetExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp1;
        Node *exp2;
        Node *exp3;
};

class SizeOfExp : public Node {
    public:
        SizeOfExp(string filename, int line, Node *exp);
        ~SizeOfExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};

class BinOpExp : public Node {
    public:
        BinOpExp(string filename, int line, Node *exp1, Node *exp2);
        ~BinOpExp();
        void printAST(int tab);
    protected:
        virtual Value *calculate() = 0;
        virtual string opStr() = 0;
        Node *exp1;
        Node *exp2;
};

class AddExp : public BinOpExp {
    public:
        AddExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class SubExp : public BinOpExp {
    public:
        SubExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class MulExp : public BinOpExp {
    public:
        MulExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class DivExp : public BinOpExp {
    public:
        DivExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class RemExp : public BinOpExp {
    public:
        RemExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class EquExp : public BinOpExp {
    public:
        EquExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class NEqExp : public BinOpExp {
    public:
        NEqExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class LoTExp : public BinOpExp {
    public:
        LoTExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class GrTExp : public BinOpExp {
    public:
        GrTExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class LEqExp : public BinOpExp {
    public:
        LEqExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class GEqExp : public BinOpExp {
    public:
        GEqExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class AndExp : public BinOpExp {
    public:
        AndExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class OrExp : public BinOpExp {
    public:
        OrExp(string filename, int line, Node *exp1, Node *exp2);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class UnaOpExp : public Node {
    public:
        UnaOpExp(string filename, int line, Node *exp);
        ~UnaOpExp();
        void printAST(int tab);
    protected:
        virtual Value *calculate() = 0;
        virtual string opStr() = 0;
        Node *exp;
};

class MinExp : public UnaOpExp {
    public:
        MinExp(string filename, int line, Node *exp);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class NotExp : public UnaOpExp {
    public:
        NotExp(string filename, int line, Node *exp);
        Node *copy();
    protected:
        Value *calculate();
        string opStr();
};

class ToStrExp : public Node {
    public:
        ToStrExp(string filename, int line, Node* exp);
        ~ToStrExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};

class ToCharExp : public Node {
    public:
        ToCharExp(string filename, int line, Node* exp);
        ~ToCharExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};

class ToIntExp : public Node {
    public:
        ToIntExp(string filename, int line, Node* exp);
        ~ToIntExp();
        void printAST(int tab);
        Node *copy();
    private:
        Node *exp;
};



class IntExp : public Node {
    public:
        IntExp(string filename, int line, string s);
        ~IntExp();
        void printAST(int tab);
        Node *copy();
    private:
        string s;
};

class BoolExp : public Node {
    public:
        BoolExp(string filename, int line, bool b);
        ~BoolExp();
        void printAST(int tab);
        Node *copy();
    private:
        bool b;
};

class StringExp : public Node {
    public:
        StringExp(string filename, int line, string s);
        ~StringExp();
        void printAST(int tab);
        Node *copy();
    private:
        string s;
};

class CharExp : public Node {
    public:
        CharExp(string filename, int line, char c);
        ~CharExp();
        void printAST(int tab);
        Node *copy();
    private:
        char c;
};



#endif
