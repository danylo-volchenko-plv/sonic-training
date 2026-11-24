/**
  * @file upper.c
  * @brief convert text to upper-case
  */
/* vim: set noet ts=4 sw=4: */
/* include files */
#include <stddef.h>
#include "conv.h"

/* macro definitions */
/* bit #5 is responsible for case since lower and upper-case
 * chars are exactly 32 positions apart. */
#define casebit 0x20

/* type definitions */

/* variable declarations */

/* function prototypes */

/* function definitions */
char *toupper_(char *str, size_t len, char *out)
{
	for (size_t l = 0; l <= len; l++)
		out[l] = (str[l] & casebit) ? (str[l] ^ casebit) : str[l];

	return out;
}
