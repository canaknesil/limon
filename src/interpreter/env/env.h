#ifndef ENV_H
#define ENV_H


void *emptyFrame(void *nextEnv); // create empty frame
void deleteFrame(void *env); // delete frame

char applyEnv(void *_env, char *var, void **val); // search for a variable in an environment
char extendFrame(void *env, char *var, void *val); // add a variable to a frame
char setEnv(void *env, char *var, void *newVal); // set an already existing variable in an environment


#endif
