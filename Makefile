
# USER PARAMETERS
SRCDIR := ./src
PARSERDIR := ./src/parser
BUILDDIR := ./build
BINDIR := ./bin

LEX := lex
YACC := yacc
LEX_OUT := $(PARSERDIR)/lex.yy.c
YACC_C := $(PARSERDIR)/y.tab.c
YACC_H := $(PARSERDIR)/y.tab.h
LEX_IN := $(PARSERDIR)/kiss.l
YACC_IN := $(PARSERDIR)/kiss.y

CXX := g++
CXXFLAGS := -Wall -g
LDFLAGS := 


# IMPLICIT VARIABLES
TARGET := $(BINDIR)/kiss
SRCS := $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))
HEADERS := $(shell find $(SRCDIR) -type f -name "*.h")


all: $(TARGET)
.PHONY: clean


$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	-rm -rf $(BUILDDIR)/*
	-rm -rf $(BINDIR)/*