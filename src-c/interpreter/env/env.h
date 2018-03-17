#ifndef ENV_H
#define ENV_H


void *emptyFrame(void *nextEnv); // create empty frame
void deleteFrame(void *env); // delete frame

/*
Searchs for a variable in an environment, sets *val to to its binding.
Returns false if variable does not exist
*/
char applyEnv(void *env, char *var, void **val); 

/* 
Adds a variable to a frame
if variable alredy exists returns false
*/
char extendFrame(void *env, char *var, void *val); 

/*
Sets an already existing variable in an environment
Returns false if the variable does not exist in the environment. 
*/
char setEnv(void *env, char *var, void *newVal); 


#endif
