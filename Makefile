
SRCDIR = ./src
BUILDDIR = ./build
BINDIR = ./bin
PARSERDIR = ./src

CC = gcc
CFLAGS = -Wall -g
LDFLAGS = 
LIBS = 

TARGET = $(BINDIR)/run
SRCS = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/**/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
HEADERS = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/**/*.h)
BUILDSUBDIRS = $(patsubst $(SRCDIR)/%/.c, $(BUILDDIR)/%, $(SRCS))



all: parser $(TARGET)
.PHONY: parser clean install



$(OBJS): $(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(TARGET): $(OBJS) 
	$(CC) $(LDFLAGS) $(LIBS) -o $@ $(OBJS)


parser:
	$(MAKE) -C $(PARSERDIR) -f Makefile-parser