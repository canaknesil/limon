#include <fileInterp.h>

#include <parser.h>
#include <node.h>

#include <iostream>
#include <stdio.h>

using namespace std;


int interpTopFile(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f) {
        cout << "Can't open file \"" << filename << "\"" << endl;
        return 1;
    }

    Node *prog = yybegin(f);
    
    fclose(f);
    
    if (!prog) return 1;

    prog->printAST();

    return 0;
}