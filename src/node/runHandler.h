#ifndef RUNHANDLER_H
#define RUNHANDLER_H

#include <garbageCollector.h>
#include <environment.h>
#include <value.h>

#include <string>


class RunHandler {
 public:

  /*
   * This method should be implemented by limon interpreter so that
   * limon files can run other limon files.
   */
  static Value *interpretFile(string filename, GarbageCollector *gc, Environment<Value *> *e);
};


#endif
