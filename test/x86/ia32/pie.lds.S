OUTPUT_ARCH(i386)
TARGET(elf32-i386)
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
