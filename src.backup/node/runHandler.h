#ifndef RUNHANDLER_H
#define RUNHANDLER_H

#include <garbageCollector.h>
#include <environment.h>
#include <value.h>

#include <string>


class RunHandler {
    public:
        static Value *interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e);
};


#endif