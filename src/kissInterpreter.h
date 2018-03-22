#ifndef FILEINTERP_H
#define FILEINTERP_H

#include <environment.h>

#include <string>

using namespace std;

class KissInterpreter
{
  public:
		static int interpretTopFile(string filename);
		static int interpretFile(string filename, Environment *e);
};

#endif
