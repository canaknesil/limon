LIB := lib
SYSIMAGE := $(LIB)/LimonSystemImage.so
SRC_JL=$(find . -name '*.jl')

all: parser $(SYSIMAGE)
.PHONY: clean check

$(SYSIMAGE): $(SRC_JL)
	mkdir -p $(LIB)
	julia --color=yes -q make_sys_image.jl $(SYSIMAGE)

parser:
	$(MAKE) -C limon-parser

clean:
	$(MAKE) -C limon-parser clean_exe
	rm -rf $(LIB)

check:
	$(MAKE) -C limon-parser check
	bin/limon test/limon-test-top.lmn
