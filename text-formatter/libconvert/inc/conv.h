/**
  * @file conv.h
  * @brief libconvert public interface
  */
/* vim: set noet ts=4 sw=4: */
#include <stdlib.h>
#if !defined(__CONV_H__)
#define __CONV_H__ 1

#ifdef __cplusplus
extern "C" {
#endif
/* include files */
#include <stddef.h>

/* macro definitions */

/* type definitions */
typedef char * (*convfn)(char *str, size_t len, char *out);

/* variable declarations */

/* function prototypes */
static inline char *convert(char *str, size_t len, convfn op);

char *toupper_(char* str, size_t len, char *out);
char *tolower_(char* str, size_t len, char *out);

/* function definitions */
static inline char *convert(char *str, size_t len, convfn op)
{
	if (str == NULL || *str == '\0')
		return str;

	char *res = calloc(len + 1, sizeof(char));
	if (res == NULL)
		return NULL;

	op(str, len, res);
	return res;
}

#ifdef __cplusplus
}
#endif

#endif /* __CONV_H__ */

