LIB := lib
SYSIMAGE := $(LIB)/LimonSystemImage.so

all: sysimage
.PHONY: clean

sysimage:
	mkdir -p $(LIB)
	julia --color=yes -q make_sys_image.jl $(SYSIMAGE)

clean:
	rm -rf $(LIB)
