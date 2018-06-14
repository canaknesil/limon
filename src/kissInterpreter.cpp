#include <kissInterpreter.h>

#include <parser.h>
#include <node.h>
#include <runHandler.h>
#include <environment.h>
#include <garbageCollector.h>

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <libgen.h>

using namespace std;



Value *RunHandler::interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e) {
    return KissInterpreter::interpretFile(filename, gc, e);
}




Value *KissInterpreter::interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e)
{
    char currDir[MAX_PATH_LEN];
    getcwd(currDir, MAX_PATH_LEN);

    char fnameCopy [MAX_PATH_LEN];
    strcpy(fnameCopy, filename.c_str());
    chdir(dirname(fnameCopy));

    strcpy(fnameCopy, filename.c_str());

    FILE *f = fopen(basename(fnameCopy), "r");
    if (!f) {
        cout << "\nCannot open file \"" + filename + "\"" << endl;
        chdir(currDir);
        return nullptr;
    }

    Node *program = KissParser::parse(f, filename);

    fclose(f);

    if (!program) {
        chdir(currDir);
        return nullptr;
    }

    Value *val = program->evaluate(gc, e);
    delete program;

    chdir(currDir);
    return val;
}

int KissInterpreter::interpretTopFile(string filename)
{
    Value *val = nullptr;
    try {

        TriColorGC *gc = new TriColorGC();
        Environment<Value *> *env = new Environment<Value *>(gc, nullptr);
    
        val = KissInterpreter::interpretFile(filename, gc, env);
        if (val) cout << "Program ended with value: \n" << val->toString() << endl;

        gc->collect(set<GarbageCollector::Item *>());
        
        delete gc;

    } catch (exception &exc) {
        cout << exc.what() << endl;
    }
    
    if (val) return 0;
    else return 1;
}

