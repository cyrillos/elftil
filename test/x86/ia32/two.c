#include <stdio.h>
#include <stdlib.h>

#include "header.h"

static const char msg[] = "Hello two.c\n";

int foo2(const struct_t *s1, const struct_t *s2)
{
	print("Hello foo2\n");
	sys_write(1, s1->str1, __builtin_strlen(s1->str1));
	sys_write(1, s1->str2, __builtin_strlen(s1->str2));
	return foo3(s1, s2);
}
