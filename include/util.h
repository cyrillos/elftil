#ifndef __UTIL_H__
#define __UTIL_H__

#include <string.h>

#include "log.h"
#include "types.h"

#define __xalloc(op, size, ...)						\
	({								\
		void *___p = op(__VA_ARGS__);				\
		if (!___p)						\
			pr_err("%s: Can't allocate %li bytes\n",	\
			       __func__, (long)(size));			\
		___p;							\
	})

#define xstrdup(str)		__xalloc(strdup, strlen(str) + 1, str)
#define xmalloc(size)		__xalloc(malloc, size, size)
#define xzalloc(size)		__xalloc(calloc, size, 1, size)
#define xrealloc(p, size)	__xalloc(realloc, size, p, size)

#define xfree(p)		do { if (p) free(p); } while (0)

#define xrealloc_safe(pptr, size)					\
	({								\
		int __ret = -1;						\
		void *new = xrealloc(*pptr, size);			\
		if (new) {						\
			*pptr = new;					\
			__ret = 0;					\
		}							\
		__ret;							\
	 })

#define memzero_p(p)		memset(p, 0, sizeof(*p))
#define memzero(p, size)	memset(p, 0, size)

static bool __ptr_oob(const void *ptr, const void *start, const size_t size)
{
	const void *end = (const void *)((const unsigned long)start + size);
	return ptr > end || ptr < start;
}

static bool test_pointer(const void *ptr, const void *start, const size_t size,
			 const char *name, const char *file, const int line)
{
	if (__ptr_oob(ptr, start, size)) {
		pr_err("Corrupted pointer %p (%s) at %s:%d\n",
		       ptr, name, file, line);
		return true;
	}
	return false;
}

#define ptr_func_exit(__ptr)						\
	do {								\
		if (test_pointer((__ptr), mem, size, #__ptr,		\
				 __FILE__, __LINE__))			\
			return -1;					\
	} while (0)

#endif /* __UTIL_H__ */
