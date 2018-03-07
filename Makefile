
# USER PARAMETERS
SRCDIR := ./src
BUILDDIR := ./build
BINDIR := ./bin
PARSERDIR := ./src

CC := gcc
CFLAGS := -Wall -g
LDFLAGS := 
LIBS := 

# IMPLICIT VARIABLES
TARGET := $(BINDIR)/kiss
SRCS = $(shell find $(SRCDIR) -type f -name "*.c")
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
HEADERS = $(shell find $(SRCDIR) -type f -name "*.h")
BUILDSUBDIRS = $(sort $(dir $(OBJS)))



all: parser $(TARGET)
.PHONY: parser clean install


$(TARGET): $(BUILDSUBDIRS) $(OBJS)  
	$(CC) $(LDFLAGS) $(LIBS) -o $@ $(OBJS)

$(OBJS): $(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	

$(BUILDSUBDIRS):
	mkdir -p $@


parser:
	$(MAKE) -C $(PARSERDIR) -f Makefile-parser


clean:
	$(MAKE) -C $(PARSERDIR) -f Makefile-parser clean
	-rm -rf $(BUILDDIR)/*
	-rm -rf $(BINDIR)/*