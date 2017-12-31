run: y.tab.h y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o run

y.tab.h y.tab.c: kiss.y
	yacc -d kiss.y

lex.yy.c: y.tab.h kiss.l
	lex kiss.l


