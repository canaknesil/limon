
VALDIR := ../../src/value

test: $(VALDIR)/value.h $(VALDIR)/value.cpp main.cpp
	g++ -Wall -g -lgmpxx -lgmp -I$(VALDIR) -o $@ main.cpp $(VALDIR)/value.cpp