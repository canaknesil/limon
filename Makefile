
# USER PARAMETERS
SRCDIR := ./src
PARSERDIR := ./src/parser
BUILDDIR := ./build
BINDIR := ./bin
TESTDIR := ./test # not in use right now

LEX := flex # gcc implementations should be used for flex and bison
YACC := bison
LEX_IN := $(PARSERDIR)/kiss.l
YACC_IN := $(PARSERDIR)/kiss.y

CXX := g++
CXXFLAGS := -Wall -g -std=c++11
LDFLAGS := -lgmpxx -lgmp


# IMPLICIT VARIABLES
LEX_OUT_PRE := lex.yy

# DON'T CHAGE (name used in the kiss.l file)
YACC_OUT_PRE := y.tab

LEX_OUT := $(PARSERDIR)/$(LEX_OUT_PRE).cpp
YACC_OUT := $(PARSERDIR)/$(YACC_OUT_PRE).cpp
YACC_OUT_H := $(PARSERDIR)/$(YACC_OUT_PRE).h

TARGET := $(BINDIR)/limon

SRCS := $(sort $(shell find $(SRCDIR) -type f -name "*.cpp") $(LEX_OUT) $(YACC_OUT))
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))
HEADERS := $(sort $(shell find $(SRCDIR) -type f -name "*.h") $(LEX_OUT) $(YACC_OUT))
INCDIRS := $(patsubst %, -I%, $(sort $(dir $(HEADERS))))




all: parser $(TARGET)
.PHONY: clean_all clean_parser clean_obj parser


parser: $(LEX_OUT)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(shell dirname $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCDIRS)

# for lex and yacc rules, only .cpp files are used since .h files are created alongside with them
$(LEX_OUT): $(LEX_IN) $(YACC_OUT)
	$(LEX) -o $@ $(LEX_IN)

$(YACC_OUT): $(YACC_IN)
	$(YACC) --defines=$(YACC_OUT_H) --output=$(YACC_OUT) $(YACC_IN)


clean_all: clean_parser clean_obj

clean_parser:
	-rm -f $(YACC_OUT_H)
	-rm -f $(YACC_OUT)
	-rm -f $(LEX_OUT)

clean_obj:
	-rm -rf $(BUILDDIR)
	-rm -rf $(BINDIR)

