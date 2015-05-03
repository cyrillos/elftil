#include <stdio.h>
#include <stdlib.h>

#include "header.h"

const struct_t s1 = {
	.str1	= "String1 s1\n",
	.str2	= "String2 s2\n",
};

int foo3(const struct_t *s1, const struct_t *s2)
{
	sys_write(1, s1->str1, __builtin_strlen(s1->str1));
	sys_write(1, s1->str2, __builtin_strlen(s1->str2));
	sys_exit(0);
}
