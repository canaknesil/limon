#include <kissInterpreter.h>

#include <parser.h>
#include <node.h>
#include <environment.h>

#include <iostream>
#include <stdio.h>

using namespace std;


class FileKissParser : public KissParser
{
  public:
    FileKissParser(Environment<Value *> *e) {
        this->e = e;
    }

    void interpretProgram(Node *prog) {
        prog->printAST();
        try {
            prog->evaluate(e);
        } catch (NodeException &exc) {
            cout << exc.what() << endl;
        }
    }

  private:
    Environment<Value *> *e;
};



int KissInterpreter::interpretFile(string filename, Environment<Value *> *e)
{
    FILE *f = fopen(filename.c_str(), "r");
    if (!f) {
        cout << "Unable to open file \"" << filename << "\"." << endl;
        return 1;
    }

    int res = FileKissParser(e).parse(f, filename);

    fclose(f);

    return res;
}

int KissInterpreter::interpretTopFile(string filename)
{
    return KissInterpreter::interpretFile(filename, new Environment<Value *>(nullptr));
}

