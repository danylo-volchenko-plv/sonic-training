/**
  * @file calc.h
  * @brief calculation library public header
  */
/* vim: set noet ts=4 sw=4: */
#if !defined(__CALC_H__)
#define __CALC_H__ 1

#ifdef __cplusplus
extern "C" {
#endif
/* include files */
#include <stdint.h>
#include <stdbool.h>

/* macro definitions */

/* type definitions */
typedef int32_t  s32;
typedef uint32_t u32;
typedef int64_t  s64;
typedef long double f64;

typedef struct operand {
	f64 f64v;
	bool valid;
} Operand;

typedef Operand (*calc_op)(Operand lhs, Operand rhs); 

/* variable declarations */

/* function prototypes */
Operand perform_op(Operand lhs, Operand rhs, calc_op op);

Operand add(Operand lhs, Operand rhs);

Operand sub(Operand lhs, Operand rhs);

Operand mdiv(Operand lhs, Operand rhs);

Operand mul(Operand lhs, Operand rhs);

Operand msqrt(Operand num, Operand rhs);

Operand fact(Operand num, Operand rhs);

/* function definitions */

#ifdef __cplusplus
}
#endif

#endif /* __CALC_H__ */

