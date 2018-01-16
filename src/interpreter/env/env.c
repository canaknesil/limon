#include "env.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


void deleteEnv(void *_env)
{
	struct env *env = _env;

	if (env != NULL) {
		deleteEnv(env->next);
		deleteBindingList(env->bl);
		free(env);
	}
}


void *applyBindingList(struct bindingList *bl, char *var)
{
	if (bl == NULL) return NULL;
	
	if (strcmp(bl->var, var) == 0) {
		return bl->val;
	} else {
		return applyBindingList(bl->next, var);
	}
}


void *applyEnv(void *_env, char *var)
{
	struct env *env = _env;

	if (env == NULL) return NULL;
	
	void *val = NULL;
	if ((val = applyBindingList(env->bl, var)) != NULL) {
		return val;
	} else {
		return applyEnv(env->next, var);
	}
}


void extendEnv(void *_env, char *var, void *val)
{
	struct env *env = _env;

	struct bindingList *newBl = malloc(sizeof(struct bindingList));
	
	newBl->var = malloc(strlen(var) + 1);
	strcpy(newBl->var, var);
	
	newBl->val = val;
	
	newBl->next = env->bl;
	env->bl = newBl;
}































