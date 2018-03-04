

all: tryTest test
.PHONY: tryTest

test: test.tc node.h node.c Makefile
	gcc node.c -x c test.tc -o $@
	
tryTest: tryTest.tc tryCatch.h tryCatch.c
	gcc tryCatch.c -x c tryTest.tc -o tryTest