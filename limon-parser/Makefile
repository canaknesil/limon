# This Makefile is designed to be simple and readable.  It does not
# aim at portability.  It requires GNU Make.

BASE = limon-parser
BISON = bison
CXX = g++
CXXFLAGS = -std=c++11
FLEX = flex
BISONFLAGS = --verbose --report-file=yacc-state-report
XSLTPROC = xsltproc

all: $(BASE)

%.cc %.hh %.xml %.gv: %.yy
	$(BISON) $(BISONFLAGS) -o $*.cc $<

%.cc: %.ll
	$(FLEX) $(FLEXFLAGS) -o$@ $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o$@ $<

$(BASE): $(BASE).o driver.o parser.o scanner.o
	$(CXX) -o $@ $^

$(BASE).o: parser.hh
parser.o: parser.hh
scanner.o: parser.hh

run: $(BASE)
	@echo "Type arithmetic expressions.  Quit with ctrl-d."
	./$< -

html: parser.html
%.html: %.xml
	$(XSLTPROC) $(XSLTPROCFLAGS) -o $@ $$($(BISON) --print-datadir)/xslt/xml2xhtml.xsl $<

CLEANFILES =										\
  $(BASE) *.o										\
  parser.hh parser.cc parser.output parser.xml parser.html parser.gv location.hh	\
  scanner.cc yacc-state-report

clean:
	rm -f $(CLEANFILES)

clean_exe:
	rm -f $(BASE)

check:
	@echo Parsing test/all-nodes.lmn
	./$(BASE) test/all-nodes.lmn > /dev/null
