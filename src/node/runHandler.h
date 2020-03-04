#ifndef RUNHANDLER_H
#define RUNHANDLER_H

#include <garbageCollector.h>
#include <environment.h>
#include <value.h>
#include <evaluationState.h>

#include <string>


class RunHandler {
 public:

  /*
   * This method should be implemented by limon interpreter so that
   * limon files can run other limon files.
   */
  static Value *interpretFile(string filename, struct evaluationState state);
};


#endif
