#ifndef EVALUATIONSTATE_H
#define EVALUATIONSTATE_H

#include <garbageCollector.h>
#include <environment.h>
#include <functionStack.h>

struct evaluationState
{
  GarbageCollector *garbageCollector;
  Environment<Value *> *environment;
  FunctionStack * functionStack;
};

#endif
