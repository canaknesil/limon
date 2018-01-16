#ifndef ENV_H
#define ENV_H


void *emptyFrame(void *nextEnv);
void deleteEnv(void *env);

void *applyEnv(void *env, char *var);
void extendEnv(void *env, char *var, void *val);


#endif
