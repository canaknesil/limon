
# USER PARAMETERS
SRCDIR := ./src
PARSERDIR := ./src/parser
ALLBUILDDIR := ./build
BINDIR := ./bin
TESTDIR := ./test

LEX := flex
YACC := bison
LEX_OUT_PRE := lex.yy
YACC_OUT_PRE := y.tab
LEX_IN := $(PARSERDIR)/kiss.l
YACC_IN := $(PARSERDIR)/kiss.y

CXX := g++
CXXFLAGS := -Wall -g -std=c++11
LDFLAGS := -static -lgmpxx -static -lgmp


# IMPLICIT VARIABLES
PARSERBUILDDIR := $(ALLBUILDDIR)/parser
BUILDDIR := $(ALLBUILDDIR)/other

TARGET := $(BINDIR)/kiss
SRCS := $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))
HEADERS := $(shell find $(SRCDIR) -type f -name "*.h")
INCDIRS := $(patsubst %, -I%, $(sort $(dir $(HEADERS))))


all: $(TARGET)
.PHONY: clean


$(TARGET): $(OBJS) $(PARSERBUILDDIR)/$(LEX_OUT_PRE).o $(PARSERBUILDDIR)/$(YACC_OUT_PRE).o
	$(CXX) -o $@ $(OBJS) $(PARSERBUILDDIR)/$(LEX_OUT_PRE).o $(PARSERBUILDDIR)/$(YACC_OUT_PRE).o $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCDIRS)

$(PARSERBUILDDIR)/%.o: $(PARSERDIR)/%.cc
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCDIRS) 

$(PARSERDIR)/$(LEX_OUT_PRE).cc: $(LEX_IN) $(PARSERDIR)/$(YACC_OUT_PRE).cc
	$(LEX) -o $(PARSERDIR)/$(LEX_OUT_PRE).cc $(LEX_IN)

$(PARSERDIR)/$(YACC_OUT_PRE).cc: $(YACC_IN)
	$(YACC) --defines=$(PARSERDIR)/$(YACC_OUT_PRE).h --output=$(PARSERDIR)/$(YACC_OUT_PRE).cc $(YACC_IN)


clean:
	-rm -rf $(ALLBUILDDIR)/*
	-rm -rf $(BINDIR)/*
	-rm -f $(PARSERDIR)/$(YACC_OUT_PRE).h
	-rm -f $(PARSERDIR)/$(YACC_OUT_PRE).cc
	-rm -f $(PARSERDIR)/$(LEX_OUT_PRE).cc
