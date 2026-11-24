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
#include <stddef.h>
#include <stdint.h>

#include "conv.h"

/* macro definitions */
#define countof(arr) \
	(sizeof((arr)) / sizeof(((arr)[0])))

/* type definitions */
typedef int32_t s32;
typedef uint32_t u32;

/* variable declarations */

/* function prototypes */
/* input / output */
void prompt(const char *const str);
void getline(char *str, size_t *len);
/* op */
void handler_noop(char cmd);
char *command_handler(char cmd, char *str, size_t len);

/* function definitions */

#ifdef __cplusplus
}
#endif

#endif /* __APP_H__ */

