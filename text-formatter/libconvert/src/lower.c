/**
  * @file lower.c
  * @brief convert text to lower-case
  */
/* vim: set noet ts=4 sw=4: */
/* include files */
#include <stddef.h>
#include "conv.h"

/* macro definitions */
#define casebit 0x20

/* type definitions */

/* variable declarations */

/* function prototypes */

/* function definitions */
char *tolower_(char *str, size_t len, char *out)
{
	for (size_t l = 0; l <= len; l++)
		out[l] = (str[l] & casebit) ? str[l] : (str[l] ^ casebit);

	return out;
}
