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


#endif
