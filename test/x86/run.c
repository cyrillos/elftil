#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#include "../../include/compiler.h"

#ifdef CONFIG_X86_32
# include "generated32.c"
#else
# include "generated64.c"
#endif

/*
 * Entry point in relocatable object file
 */
extern int foo1(void);

int main(int argc, char *argv[])
{
	size_t i, j, size = sizeof(stream) + nr_gotpcrel * sizeof(long);
	void *mem = mmap(NULL, size,
			 PROT_READ | PROT_WRITE | PROT_EXEC,
			 MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	int (*f)(void);
	int fd;

	if (mem == MAP_FAILED) {
		printf("Can't map: %m\n");
		exit(1);
	} else
		printf("exec map at %p\n", mem);

	memcpy(mem, stream, sizeof(stream));

	for (i = 0, j = 0; i < ARRAY_SIZE(elf_relocs); i++) {
		if (elf_relocs[i].type) {
			long *where = mem + elf_relocs[i].offset;
			long *p = mem + sizeof(stream);

			if (elf_relocs[i].type & 2) {
				int *v = (int *)where;
				int rel;

				p[j] = (long)mem + elf_relocs[i].value;
				printf("p[%d] -> %lx\n", j, p[j]);

				rel = (unsigned)((void *)&p[j] - (void *)mem) - elf_relocs[i].offset - elf_relocs[i].addend;
				printf("\toffset %d\n", rel);

				*v = rel;
				printf("reloc %x -> %p\n", *v, v);
				where = (void *)mem + elf_relocs[i].offset + (unsigned long)*v;
				printf("patched %lx\n", *where);
				j++;
			} else
				*where = (unsigned long)elf_relocs[i].value + (long)elf_relocs[i].addend + (unsigned long)mem;
		} else {
			int *where = (mem + elf_relocs[i].offset);
			*where = elf_relocs[i].value + elf_relocs[i].addend + (unsigned long)mem;
		}
	}

	fd = open("out.o", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
		write(fd, mem, size);
	close(fd);

//	exit(0);
	f = mem + foo1_sym;
	f();

	return 0;
}
