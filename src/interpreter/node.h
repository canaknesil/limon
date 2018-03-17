#ifndef NODE_H // public interface for AST nodes and the interpreter
#define NODE_H


#define NEW_TYPE(ID, N)		((ID << 8) + N)
#define GET_N(NID)          ((NID) & 0xFF)
#define GET_UNOFF_ID(ID)    (ID >> 8)


// AST nodes: NEW_TYPE(a unique ID, number of branch)
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
#define BIN_OP_EXP			NEW_TYPE(413, 1)
#define UNI_OP_EXP			NEW_TYPE(414, 1)

#define ADD_EXP				NEW_TYPE(500, 2)
#define SUB_EXP				NEW_TYPE(501, 2)
#define MUL_EXP				NEW_TYPE(502, 2)
#define DIV_EXP				NEW_TYPE(503, 2)
#define REM_EXP				NEW_TYPE(504, 2)
#define EQ_EXP				NEW_TYPE(505, 2)
#define NEQ_EXP				NEW_TYPE(506, 2)
#define L_EXP				NEW_TYPE(507, 2)
#define G_EXP				NEW_TYPE(508, 2)
#define GEQ_EXP				NEW_TYPE(509, 2)
#define LEQ_EXP				NEW_TYPE(510, 2)
#define AND_EXP				NEW_TYPE(511, 2)
#define OR_EXP				NEW_TYPE(512, 2)

#define MIN_EXP				NEW_TYPE(513, 1)
#define NOT_EXP				NEW_TYPE(514, 1)

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



void *newNode(int type, int line, ...);
void deleteNode(void *node);
void deleteNodeRec(void *node); // for deleting itself and the branches.

void *printAST(void *node, void *env); // prints the AST for debugging
void *valueof(void *node, void *env); // simple type of evaluation

void *emptyFrameWithCEGC(void *nextEnv);

#endif


