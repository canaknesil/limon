#ifndef FILEINTERP_H
#define FILEINTERP_H

#include <environment.h>
#include <garbageCollector.h>
#include <value.h>

#include <string>

using namespace std;

class KissInterpreter
{
  public:
		static int interpretTopFile(string filename);
		static int interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e);
};


#endif
