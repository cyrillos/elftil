#ifndef HEADER_H__
#define HEADER_H__

typedef struct {
	char *str1;
	char *str2;
} struct_t;

#define print(msg)	sys_write(1, (msg), sizeof((msg)))

extern const struct_t s1;
extern const struct_t s2;

extern int sys_write(int fd, char *msg, unsigned int size);
extern int sys_exit(int code);

extern int foo1(void);
extern int foo2(const struct_t *s1, const struct_t *s2);
extern int foo3(const struct_t *s1, const struct_t *s2);

#endif /* HEADER_H__ */
