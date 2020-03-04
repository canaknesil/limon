#
# DIRECTORIES
#

SRCDIR := ./src
PARSERDIR := ./src/parser
BUILDDIR := ./build
BINDIR := ./bin
TESTDIR := ./test


#
# PARSER
#

# gnu implementations should be used for flex and bison
LEX := flex
YACC := bison
LEX_IN := $(PARSERDIR)/limon.l
YACC_IN := $(PARSERDIR)/limon.y

LEX_OUT_NAME := lex.yy

# DON'T CHAGE (name used in the limon.l file)
YACC_OUT_NAME := y.tab

LEX_OUT := $(PARSERDIR)/$(LEX_OUT_NAME).cpp
YACC_OUT := $(PARSERDIR)/$(YACC_OUT_NAME).cpp
YACC_OUT_H := $(PARSERDIR)/$(YACC_OUT_NAME).h


#
# COMPILER
#

CXX := g++
CXXFLAGS := -Wall -g -std=c++11
LDFLAGS := -lgmpxx -lgmp -lreadline

TARGET := $(BINDIR)/limon

SRCS := $(sort $(shell find $(SRCDIR) -name '*.cpp') $(YACC_OUT) $(LEX_OUT))
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS)) 
HEADERS = $(sort $(shell find $(SRCDIR) -name '*.h') $(YACC_OUT_H))
INCDIRS = $(patsubst %,-I%,$(sort $(dir $(HEADERS))))


all: $(TARGET)
.PHONY: clean clean_parser tags check


$(TARGET): $(OBJS) 
	@mkdir -p $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCDIRS)


$(LEX_OUT): $(LEX_IN) $(YACC_OUT) $(YACC_OUT_H)
	$(LEX) -o $@ $(LEX_IN)

$(YACC_OUT) $(YACC_OUT_H): $(YACC_IN)
	$(YACC) --verbose --defines=$(YACC_OUT_H) --output=$(YACC_OUT) $(YACC_IN)

check:
	$(MAKE) -C $(TESTDIR)

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

clean_parser:
	rm -f $(LEX_OUT) $(YACC_OUT) $(YACC_OUT_H)


tags:
	find src \( -name '*.cpp' -or -name '*.h' -or -name '*.l' -or -name '*.y' \) | etags -
