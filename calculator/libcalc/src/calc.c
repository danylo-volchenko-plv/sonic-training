/**
  * @file calc.c
  * @brief libalc implementation
  */
/* vim: set noet ts=4 sw=4: */
/* include files */
#include <math.h>
#include <stdio.h>

#include "calc.h"

/* macro definitions */

/* type definitions */

/* variable declarations */

/* function prototypes */

/* function definitions */
Operand perform_op(Operand lhs, Operand rhs, calc_op op)
{
	return op(lhs, rhs);
}

Operand add(Operand lhs, Operand rhs)
{
	return (Operand){.f64v = (lhs.f64v + rhs.f64v), .valid  = true};
}

Operand sub(Operand lhs, Operand rhs)
{
	return (Operand){.f64v = (lhs.f64v - rhs.f64v), .valid  = true};
}

Operand mdiv(Operand lhs, Operand rhs)
{
	if (lhs.f64v == 0 || rhs.f64v == 0) {
		fprintf(stderr, "Division of/by zero\n");
		return (Operand){.f64v = 0, .valid = false};
	}
	return (Operand){.f64v = (lhs.f64v / rhs.f64v), .valid  = true};
}

Operand mul(Operand lhs, Operand rhs)
{
	if (rhs.f64v == 0)
		return (Operand){.f64v = 0, .valid = false};
	return (Operand){.f64v = (lhs.f64v * rhs.f64v), .valid  = true};
}

Operand msqrt(Operand num, Operand rhs)
{
	(void) rhs;
	if (num.f64v < 0) {
		fprintf(stderr, "Negative number square root\n");
		return (Operand){.f64v = 0, .valid = false};
	}
	return (Operand){.f64v = sqrtl(num.f64v), .valid = true};
}

Operand fact(Operand num, Operand rhs)
{
	(void) rhs;
	if (num.f64v == 0)
		return (Operand){.f64v = 1, .valid = true};
	Operand ans = {.f64v = 1, .valid = true};
	for (s64 it = 2; it <= (s64)num.f64v; it++)
		ans.f64v = ans.f64v * it;
	return ans;
}
