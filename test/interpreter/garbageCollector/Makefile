
GCDIR := ../../src/garbageCollector

test: $(GCDIR)/garbageCollector.h $(GCDIR)/garbageCollector.cpp main.cpp
	g++ -Wall -g -std=c++11 -I$(GCDIR) -o $@ main.cpp $(GCDIR)/garbageCollector.cpp