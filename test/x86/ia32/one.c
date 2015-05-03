#include <stdio.h>
#include <stdlib.h>

#include "header.h"

const struct_t s2 = {
	.str1	= "String1 s2\n",
	.str2	= "String2 s2\n",
};

/*
 * This one we start from
 */
int foo1(void)
{
	print("Hello foo1\n");
	foo2(&s1, &s2);
	return foo3(&s1, &s2);
}
