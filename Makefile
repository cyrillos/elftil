__simak_dir=scripts/simak/scripts/
export __simak_dir

PROGRAM := elftil

include $(__simak_dir)include.mk
include $(__simak_dir)macro.mk

ccflags-y += -iquote `pwd`/include

$(eval $(call gen-built-in,src))

$(PROGRAM): src/built-in.o
	$(call msg-gen, $@)
	$(Q) $(CC) -o $@ $^

all: $(PROGRAM)
	@true
.PHONY: all

clean:
	$(call msg-gen, $@)
	$(Q) $(MAKE) $(build)=src clean
	$(Q) $(RM) $(PROGRAM)
.PHONY: all

.DEFAULT_GOAL := all
