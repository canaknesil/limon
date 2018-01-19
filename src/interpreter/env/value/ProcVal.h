#ifndef PROCVAL_H
#define PROCVAL_H



const void * ProcVal; //class   newValue(ProcVal, (void *) bVarList, (void *) body, (void *) env)

void *ProcVal_GetBVarList(void *proc);
void *ProcVal_GetBody(void *proc);
void *ProcVal_GetEnv(void *proc);



#endif


