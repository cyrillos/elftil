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
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	pushl	%ebp

#define __arg(n)	(4 * (n) + 20)(%esp)
	movl	__arg(0),%ebx
	movl	__arg(1),%ecx
	movl	__arg(2),%edx
	movl	__arg(3),%esi
	movl	__arg(4),%edi
	movl	__arg(5),%ebp
#undef __arg

	int	$0x80

	popl	%ebp
	popl	%edi
	popl	%esi
	popl	%ebx
	ret
END(__syscall_common)

SYSCALL(sys_write, 4)
SYSCALL(sys_exit, 1)
