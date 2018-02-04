#ifndef NODE_H
#define NODE_H


#define NEW_TYPE(ID, N)		((ID << 8) + N)
#define GET_N(NID)          ((NID) & 0xFF)


#define A_PROGRAM			NEW_TYPE(10, 1)
#define EMPTY_PROGRAM		NEW_TYPE(11, 0)

#define ONE_STATEMENT_SL	NEW_TYPE(21 , 1)
#define MUL_STATEMENT_SL	NEW_TYPE(22 , 2)

#define EXPRESSION_S		NEW_TYPE(31, 1)
#define COMPOUND_S			NEW_TYPE(32, 1)
#define VAR_DEF_INIT_S		NEW_TYPE(33, 1)
#define VAR_DEF_S			NEW_TYPE(34, 1)
#define IF_S				NEW_TYPE(36, 2)
#define IF_ELSE_S			NEW_TYPE(37, 3)
#define WHILE_S				NEW_TYPE(38, 2)
#define PRINT_S				NEW_TYPE(39, 1)

#define ASSIGN_EXP			NEW_TYPE(400, 2)
#define CONSTANT_EXP		NEW_TYPE(401, 1)
#define VAR_EXP				NEW_TYPE(402, 1)
#define PROC_EXP			NEW_TYPE(403, 2)
#define CALL_EXP			NEW_TYPE(404, 2)
#define ARRAY_EXP			NEW_TYPE(406, 1)
#define ARRAY_GET_EXP		NEW_TYPE(407, 2)
#define ARRAY_SET_EXP		NEW_TYPE(409, 3)
#define IF_ELSE_EXP			NEW_TYPE(412, 3)
#define ADD_EXP				NEW_TYPE(413, 2)
#define SUB_EXP				NEW_TYPE(414, 2)
#define MUL_EXP				NEW_TYPE(415, 2)
#define DIV_EXP				NEW_TYPE(416, 2)
#define REM_EXP				NEW_TYPE(417, 2)
#define MIN_EXP				NEW_TYPE(418, 1)
#define EQ_EXP				NEW_TYPE(419, 2)
#define NEQ_EXP				NEW_TYPE(420, 2)
#define L_EXP				NEW_TYPE(421, 2)
#define G_EXP				NEW_TYPE(422, 2)
#define GEQ_EXP				NEW_TYPE(423, 2)
#define LEQ_EXP				NEW_TYPE(424, 2)
#define AND_EXP				NEW_TYPE(425, 2)
#define OR_EXP				NEW_TYPE(426, 2)
#define NOT_EXP				NEW_TYPE(427, 1)

#define ONE_ASSIGN_AL		NEW_TYPE(50, 2)
#define MUL_ASSIGN_AL		NEW_TYPE(51, 3)

#define NEMPTY_ARG_LIST		NEW_TYPE(60, 1)
#define EMPTY_ARG_LIST		NEW_TYPE(61, 0)
#define ONE_ARG_AL			NEW_TYPE(62, 1)
#define MUL_ARG_AL			NEW_TYPE(63, 2)

#define NEMPTY_VAR_LIST		NEW_TYPE(70, 1)
#define EMPTY_VAR_LIST		NEW_TYPE(71, 0)
#define ONE_VAR_VL			NEW_TYPE(72, 1)
#define MUL_VAR_VL			NEW_TYPE(73, 2)

#define INTEGER_CONST		NEW_TYPE(80, 1)
#define BOOLEAN_CONST		NEW_TYPE(81, 1)
#define STRING_CONST		NEW_TYPE(82, 1)
#define CHARACTER_CONST		NEW_TYPE(83, 1)



void *newNode(int type, ...);
void deleteNode(void *node);
void deleteNodeRec(void *node);

void *printAST(void *node, void *env);
void *valueof(void *node, void *env);


#endif


