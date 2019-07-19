#ifndef FILEINTERP_H
#define FILEINTERP_H

#include <environment.h>
#include <garbageCollector.h>
#include <value.h>

#include <string>
#include <exception>

using namespace std;


#define MAX_PATH_LEN	(4096 + 255)


class KissInterpreter
{
  public:
		static int interpretTopFile(string filename);
		static Value *interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e);
};


#endif
