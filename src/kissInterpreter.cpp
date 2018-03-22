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
    FileKissParser(Environment *e) {
        this->e = e;
    }

    void interpretProgram(Node *prog) {
        prog->printAST();
    }

  private:
    Environment *e;
};



int KissInterpreter::interpretFile(string filename, Environment *e)
{
    FILE *f = fopen(filename.c_str(), "r");
    if (!f) {
        cout << "Unable to open file \"" << filename << "\"." << endl;
        return 1;
    }

    int res = FileKissParser(e).parse(f);

    fclose(f);

    return res;
}

int KissInterpreter::interpretTopFile(string filename)
{
    return KissInterpreter::interpretFile(filename, nullptr);
}
