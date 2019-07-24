SUBDIRS := core base stdlib


SUBDIRS_CHECK = $(patsubst %, %.check_phony, $(SUBDIRS))
SUBDIRS_CLEAN = $(patsubst %, %.clean_phony, $(SUBDIRS))

.all:
.PHONY: check test_results clean $(SUBDIRS_CHECK) $(SUBDIRS_CLEAN)

check: test_results $(SUBDIRS_CHECK)
	@cat test_results

test_results:
	rm -f $@
	touch $@

clean: $(SUBDIRS_CLEAN)

$(SUBDIRS_CHECK):
	$(MAKE) -C $(basename $@) check
	@echo >> test_results
	@echo TEST RESULTS FOR $(basename $@) >> test_results
	@cat $(basename $@)/test_results >> test_results

$(SUBDIRS_CLEAN):
	$(MAKE) -C $(basename $@) clean
	rm -f test_results
