obj-y += one.o
obj-y += two.o
obj-y += three.o
obj-y += syscall.o

CFLAGS := -m32 -fno-pic -Os

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $^

%.o: %.S
	gcc -c $(CFLAGS) -o $@ $^

built-in.o: $(obj-y)
	ld -r -o $@ -T pie.lds.S $^

all: built-in.o $(obj-y)
	@true
.PHONY: all

clean:
	rm -f ./*o
.PHONY: clean

.DEFAULT_GOAL := all
