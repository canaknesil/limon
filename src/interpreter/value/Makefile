cfiles = $(wildcard *.c)

test: test.tc $(wildcard *.c) $(wildcard *.h) Makefile
	gcc $(cfiles) -x c test.tc -o test
	
