#ifndef __ELFTIL_H__
#define __ELFTIL_H__

#include <unistd.h>

typedef struct {
	char		*input_filename;
	char		*stream_name;
	char		*type_name;
	char		*var_name;
	char		*sym_postfix;
	char		*nrgotpcrel_name;
} opt_t;

extern opt_t opts;

extern int handle_elf_x86_32(const opt_t *opts, char *mem, size_t size);
extern int handle_elf_x86_64(const opt_t *opts, char *mem, size_t size);

#endif /* __ELFTIL_H__ */
