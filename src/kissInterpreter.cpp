#include <kissInterpreter.h>

#include <parser.h>
#include <node.h>
#include <environment.h>
#include <garbageCollector.h>

#include <iostream>
#include <stdio.h>

using namespace std;


class FileKissParser : public KissParser
{
  public:
    FileKissParser(GarbageCollector *gc, Environment<Value *> *e) {
        this->e = e;
        this->gc = gc;
    }

    void interpretProgram(Node *prog) {
        //prog->printAST();
        try {
            prog->evaluate(gc, e);
        } catch (NodeException &exc) {
            cout << exc.what() << '\a' << endl;
        }
    }

  private:
    Environment<Value *> *e;
    GarbageCollector *gc;
};



int KissInterpreter::interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e)
{
    FILE *f = fopen(filename.c_str(), "r");
    if (!f) {
        cout << "Unable to open file \"" << filename << "\"." << endl;
        return 1;
    }

    int res = FileKissParser(gc, e).parse(f, filename);

    fclose(f);

    return res;
}

int KissInterpreter::interpretTopFile(string filename)
{
    TriColorGC *gc = new TriColorGC();
    int res = KissInterpreter::interpretFile(filename, gc, new Environment<Value *>(gc, nullptr));
    gc->collect(set<GarbageCollector::Item *>());
    delete gc;
    return res;
}

