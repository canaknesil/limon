#
# PARAMETERS
#

LIMON_TEST_FILES := allNodes.lmn emptyProgram.lmn
LIMON := ../../bin/limon
LIMON_FLAGS := --no-base --no-end-val

#
# SETUP
#

LIMON_TEST_REFERENCES := $(patsubst %.lmn, %.reference, $(LIMON_TEST_FILES))
LIMON_TEST_DIFF_FILES := $(patsubst %.lmn, %.diff, $(LIMON_TEST_FILES))

#
# RULES
#

all:
.PHONY: generate_all_references $(LIMON_TEST_REFERENCES) clean_old_references
.PHONY: check test_results $(LIMON_TEST_DIFF_FILES)


# GENERATING REFERENCE
generate_all_references: $(LIMON_TEST_REFERENCES)

$(LIMON_TEST_REFERENCES):
	if [ -f $@ ]; then mv $@ $@.`date +"%y%m%d-%H%M-%N"`; fi
	-$(LIMON) $(LIMON_FLAGS) $(basename $@).lmn > $@

clean_old_references:
	rm -f *.reference.*


# CHECK
check: test_results $(LIMON_TEST_DIFF_FILES)
	@echo
	@echo TEST RESULTS
	@cat test_results

test_results:
	rm -f test_results
	touch test_results

$(LIMON_TEST_DIFF_FILES):
	-$(LIMON) $(LIMON_FLAGS) $(basename $@).lmn > $(basename $@).output
	diff $(basename $@).reference $(basename $@).output > $@
	@if [ -s $@ ]; then\
	    echo $(basename $@) "\t: FAILED" >> test_results;\
	else\
	    echo $(basename $@) "\t: PASS" >> test_results;\
	fi

clean:
	rm -f *.diff
	rm -f *.output
	rm -f test_results
