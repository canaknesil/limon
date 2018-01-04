
SRCDIR = ./src
BUILDDIR = ./build
BINDIR = ./bin

CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 
LIBS = 

TARGET = $(BINDIR)/run
SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/**/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
HEADERS = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/**/*.h)
BUILDSUBDIRS = $(patsubst $(SRCDIR)/%/.c, $(BUILDDIR)/%, $(SRCS))

Y_IN = $(wildcard $(SRCDIR)/**/kiss.y)
Y_OUT_H = $(patsubst $(SRCDIR)/%kiss.y, $(SRCDIR)/%y.tab.h, $(Y_IN))
Y_OUT_C = $(patsubst $(SRCDIR)/%kiss.y, $(SRCDIR)/%y.tab.c, $(Y_IN))
L_DEP = $(wildcard $(SRCDIR)/**/kiss.l) $(Y_OUT_H)
L_IN = $(wildcard $(SRCDIR)/**/kiss.l)
L_OUT = $(patsubst $(SRCDIR)/%kiss.l, $(SRCDIR)/%lex.yy.c, $(L_IN))



all: $(OBJS) $(TARGET) 
.PHONY: clean install



$(OBJS): $(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
$(TARGET): $(OBJS) 
	$(CC) $(LDFLAGS) $(LIBS) -o $@ $(OBJS)



$(Y_OUT): $(Y_IN)
	yacc -d $<

$(L_OUT): $(L_DEP)
	lex kiss.l $(L_IN)


