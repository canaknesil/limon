#include "env.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "value/value.h"


struct bindingList
{
	char *var;
	void *val;
	struct bindingList *next;
};

struct env
{
	struct bindingList *bl;
	struct env *next;
};



void *emptyFrame(void *nextEnv)
{
	struct env *env = malloc(sizeof(struct env));
	env->bl = NULL;
	env->next = nextEnv;
	
	return env;
}


void deleteBindingList(struct bindingList *bl)
{
	if (bl != NULL) {
		deleteBindingList(bl->next);
		free(bl->var);
		free(bl);
	} 
}


void deleteFrame(void *_env)
{
	struct env *env = _env;
	deleteBindingList(env->bl);
	free(env);
}



char applyBindingList(struct bindingList *bl, char *var, void **val)
{
	if (bl == NULL) {
		return 0;
	}
	
	if (strcmp(bl->var, var) == 0) {
		*val = bl->val;
		return 1;
	} else {
		return applyBindingList(bl->next, var, val);
	}
}


char checkBindingList(struct bindingList *bl, char *var)
{
	if (bl == NULL) return 0;

	if (strcmp(bl->var, var) == 0) {
		return 1;
	} else {
		return checkBindingList(bl->next, var);
	}
}


char extendFrame(void *_env, char *var, void *val)
{
	struct env *env = _env;
	if (checkBindingList(env->bl, var)) return 0;

	struct bindingList *newBl = malloc(sizeof(struct bindingList));
	
	newBl->var = malloc(strlen(var) + 1);
	strcpy(newBl->var, var);
	
	newBl->val = val;
	
	newBl->next = env->bl;
	env->bl = newBl;

	return 1;
}


char setBindingList(struct bindingList *bl, char *var, void *newVal)
{
	if (bl == NULL) return 0;
	
	if (strcmp(bl->var, var) == 0) {
		bl->val = newVal;
		return 1;
	} else {
		return setBindingList(bl->next, var, newVal);
	}
}


char setEnv(void *_env, char *var, void *newVal)
{
	struct env *env = _env;

	if (env == NULL) return 0;
	
	char p;
	if ((p = setBindingList(env->bl, var, newVal))) {
		return 1;
	} else {
		return setEnv(env->next, var, newVal);
	}
}


char applyEnv(void *_env, char *var, void **val)
{
	struct env *env = _env;

	if (env == NULL) {
		return 0;
	}
	
	if (applyBindingList(env->bl, var, val)) {
		return 1;
	} else {
		return applyEnv(env->next, var, val);
	}
}






























