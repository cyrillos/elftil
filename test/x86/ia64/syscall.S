#define __ALIGN		.align 4, 0x90
#define __ALIGN_STR	".align 4, 0x90"

#define GLOBAL(name)			\
	.globl name;			\
	name:

#define ENTRY(name)			\
	.globl name;			\
	.type name, @function;		\
	__ALIGN;			\
	name:

#define END(sym)			\
	.size sym, . - sym

#define SYSCALL(name, opcode)		\
	ENTRY(name);			\
	movl	$opcode, %eax;		\
	jmp	__syscall_common;	\
	END(name)

ENTRY(__syscall_common)
	movq	%rcx, %r10
	syscall
	ret
END(__syscall_common)

SYSCALL(sys_write, 1)
SYSCALL(sys_exit, 60)
