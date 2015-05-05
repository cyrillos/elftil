BITS := 64

ifeq ($(ARCH),"ia32")
        export CFLAGS += -DCONFIG_X86_32
        BITS := 32
else
        export CFLAGS += -DCONFIG_X86_64
endif

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $^

ia$(BITS)/built-in.o:
	make -C ia$(BITS) $@

generated$(BITS).c: ia$(BITS)/built-in.o
	../../elftil -f ia$(BITS)/built-in.o > $@

run: run.o generated$(BITS).c 
	gcc $(CFLAGS) -o $@ $<

clean:
	make -C ia32 clean
	make -C ia64 clean
	rm -f ./*.o
	rm -f ./generated32.c ./generated64.c
	rm -f ./run32 ./run64
.PHONY: clean

all: run
	@true
.PHONY: all

.DEFUALT_GOAL := all
