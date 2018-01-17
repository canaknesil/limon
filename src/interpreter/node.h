#ifndef NODE_H
#define NODE_H


#define NEW_TYPE(ID, N)			((ID << 8) + N)
#define GET_N(NID)          ((NID) & 0xFF)

#define A_PROGRAM			NEW_TYPE(10, 1)
#define EMPTY_PROGRAM		NEW_TYPE(11, 0)

#define ONE_STATEMENT_SL	NEW_TYPE(20, 1)
#define MUL_STATEMENT_SL	NEW_TYPE(21, 2)

#define EXPRESSION_S		NEW_TYPE(30, 1)
#define COMPOUND_S			NEW_TYPE(31, 1)
#define VAR_DEF_INIT_S		NEW_TYPE(32, 1)
#define VAR_DEF_S			NEW_TYPE(33, 1)
#define FUNC_DEF_S			NEW_TYPE(34, 3)
#define IF_S				NEW_TYPE(35, 2)
#define IF_ELSE_S			NEW_TYPE(36, 3)
#define WHILE_S				NEW_TYPE(37, 2)
#define PRINT_S				NEW_TYPE(38, 1)

#define CONSTANT_EXP		NEW_TYPE(100, 1)

#define INTEGER_CONST		NEW_TYPE(40, 1)


void *newNode(int type, ...);
void deleteNode(void *node);
void *evaluate(void *node, void *env);


#endif


