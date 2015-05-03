OUTPUT_ARCH(i386:x86-64)
TARGET(elf64-x86-64)
SECTIONS
{
	.text : {
		*(.text*)
	}

	.data : {
		*(.data*)
		*(.bss*)
	}

	.rodata : {
		*(.rodata*)
		*(.got*)
	}

	/DISCARD/ : {
		*(.debug*)
		*(.comment*)
		*(.note*)
		*(.group*)
		*(.eh_frame*)
	}
}
