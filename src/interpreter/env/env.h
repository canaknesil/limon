#ifndef ENV_H
#define ENV_H


void *emptyFrame(void *nextEnv);
void deleteEnv(void *env);
void deleteFrame(void *env);

char applyEnv(void *_env, char *var, void **val);
char extendFrame(void *env, char *var, void *val);
char setEnv(void *env, char *var, void *newVal);


#endif
