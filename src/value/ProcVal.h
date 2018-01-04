#ifndef PROCVAL_H
#define PROCVAL_H



const void * ProcVal; //class   newValue(ProcVal, (char *) bvar, (void *) body, (void *) env)

char *ProcVal_GetBVar(void *proc);
void *ProcVal_GetBody(void *proc);
void *ProcVal_GetEnv(void *proc);



#endif


