#include <kissInterpreter.h>

#include <parser.h>
#include <node.h>

#include <iostream>
#include <stdio.h>

using namespace std;


class FileKissParser : public KissParser
{
  public:
    void interpretExp(Node *exp)
    {
        cout << "Expression" << endl;
    }
};



int KissInterpreter::interpretFile(string filename, Environment *e)
{
    FILE *f = fopen(filename.c_str(), "r");
    if (!f) {
        cout << "Unable to open file \"" << filename << "\"." << endl;
        return 1;
    }

    int res = FileKissParser().parse(f);

    fclose(f);

    return res;
}

int KissInterpreter::interpretTopFile(string filename)
{
    return KissInterpreter::interpretFile(filename, nullptr);
}
