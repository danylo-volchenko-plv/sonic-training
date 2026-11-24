/**
  * @file app.h
  * @brief public interface for app functionality
  */
/* vim: set noet ts=4 sw=4: */
#if !defined(__APP_H__)
#define __APP_H__ 1

#ifdef __cplusplus
extern "C" {
#endif
/* include files */
#include "calc.h"

/* macro definitions */
#define countof(arr) \
	(sizeof((arr)) / sizeof(((arr)[0])))

/* type definitions */

/* variable declarations */

/* function prototypes */
/* input / output */
void prompt(const char *const str);
void getline(char *str, u32 len);
Operand parse_num(const char *const numstr, char *errmsg);
/* op */
void handler_noop(char cmd);
Operand command_handler(char cmd, Operand lhs, Operand rhs);

/* function definitions */

#ifdef __cplusplus
}
#endif

#endif /* __APP_H__ */

