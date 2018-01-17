#ifndef NODE_H
#define NODE_H


#define NEW_TYPE(ID, N)		((ID << 8) + N)
#define GET_N(NID)          ((NID) & 0xFF)


#define A_PROGRAM			NEW_TYPE(10, 1)
#define EMPTY_PROGRAM		NEW_TYPE(11, 0)

#define ONE_STATEMENT_SL	NEW_TYPE(12, 1)
#define MUL_STATEMENT_SL	NEW_TYPE(13, 2)

#define EXPRESSION_S		NEW_TYPE(20, 1)
#define COMPOUND_S			NEW_TYPE(21, 1)
#define VAR_DEF_INIT_S		NEW_TYPE(22, 1)
#define VAR_DEF_S			NEW_TYPE(23, 1)
#define FUNC_DEF_S			NEW_TYPE(24, 3)
#define IF_S				NEW_TYPE(25, 2)
#define IF_ELSE_S			NEW_TYPE(26, 3)
#define WHILE_S				NEW_TYPE(27, 2)
#define PRINT_S				NEW_TYPE(28, 1)

#define ASSIGN_EXP			NEW_TYPE(100, 2)
#define CONSTANT_EXP		NEW_TYPE(101, 1)
#define VAR_EXP				NEW_TYPE(102, 1)
#define PROC_EXP			NEW_TYPE(103, 2)
#define VAR_CALL_EXP		NEW_TYPE(104, 2)
#define EXP_CALL_EXP		NEW_TYPE(105, 2)
#define ARRAY_EXP			NEW_TYPE(106, 1)
#define VAR_ARRAY_GET_EXP	NEW_TYPE(107, 2)
#define EXP_ARRAY_GET_EXP	NEW_TYPE(108, 2)
#define VAR_ARRAY_SET_EXP	NEW_TYPE(109, 3)
#define EXP_ARRAY_SET_EXP	NEW_TYPE(110, 3)
#define IF_EXP				NEW_TYPE(111, 2)
#define IF_ELSE_EXP			NEW_TYPE(112, 3)
#define ADD_EXP				NEW_TYPE(113, 2)
#define SUB_EXP				NEW_TYPE(114, 2)
#define MUL_EXP				NEW_TYPE(115, 2)
#define DIV_EXP				NEW_TYPE(116, 2)
#define REM_EXP				NEW_TYPE(117, 2)
#define MIN_EXP				NEW_TYPE(118, 1)
#define EQ_EXP				NEW_TYPE(119, 2)
#define NEQ_EXP				NEW_TYPE(120, 2)
#define L_EXP				NEW_TYPE(121, 2)
#define G_EXP				NEW_TYPE(122, 2)
#define GEQ_EXP				NEW_TYPE(123, 2)
#define LEQ_EXP				NEW_TYPE(124, 2)
#define AND_EXP				NEW_TYPE(125, 2)
#define OR_EXP				NEW_TYPE(126, 2)
#define NOT_EXP				NEW_TYPE(127, 1)

#define ONE_ASSIGN_AL		NEW_TYPE(30, 2)
#define MUL_ASSIGN_AL		NEW_TYPE(31, 3)

#define NEMPTY_ARG_LIST		NEW_TYPE(32, 1)
#define EMPTY_ARG_LIST		NEW_TYPE(33, 0)
#define ONE_ARG_AL			NEW_TYPE(34, 1)
#define MUL_ARG_AL			NEW_TYPE(35, 2)

#define NEMPTY_VAR_LIST		NEW_TYPE(36, 1)
#define EMPTY_VAR_LIST		NEW_TYPE(37, 0)
#define ONE_VAR_VL			NEW_TYPE(38, 1)
#define MUL_VAR_VL			NEW_TYPE(39, 2)

#define INTEGER_CONST		NEW_TYPE(40, 1)
#define BOOLEAN_CONST		NEW_TYPE(41, 1)


void *newNode(int type, ...);
void deleteNode(void *node);
void deleteNodeRec(void *node);
void *evaluate(void *node, void *env);


#endif


