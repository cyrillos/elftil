#ifdef CONFIG_X86_64
# undef CONFIG_X86_64
#endif

#ifndef CONFIG_X86_32
# define CONFIG_X86_32
#endif

#define handle_elf	handle_elf_x86_32

#define Ehdr_t		Elf32_Ehdr
#define Shdr_t		Elf32_Shdr
#define Sym_t		Elf32_Sym
#define Rel_t		Elf32_Rel
#define Rela_t		Elf32_Rela

#define ELF_ST_TYPE	ELF32_ST_TYPE
#define ELF_ST_BIND	ELF32_ST_BIND

#define ELF_R_SYM	ELF32_R_SYM
#define ELF_R_TYPE	ELF32_R_TYPE

#include "elf-x86.c"
