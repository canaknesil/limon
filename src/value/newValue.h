#ifndef NEWVALUE_H
#define NEWVALUE_H


// top level functions
void *newValue(const void *des, ...);
void deleteValue(void *val);
void printValue(void *val);
char checkValueType(const void *des, void *val);


#endif
