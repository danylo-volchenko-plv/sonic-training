/**
  * @file app.c
  * @brief Common calculator functions implementation
  */
/* vim: set noet ts=4 sw=4: */
/* include files */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "app.h"

/* macro definitions */

/* type definitions */

/* variable declarations */
static const calc_op dispatch[256] = {
	['+'] = add,
	['-'] = sub,
	['*'] = mul,
	['/'] = mdiv,
	['!'] = fact,
	['#'] = msqrt,
};

/* function prototypes */

/* function definitions */

void prompt(const char *const str)
{
	fprintf(stdout, "%s", str);
	fflush(stdout);
}

void getline(char *str, u32 len)
{
	const char *read = fgets(str, (int)len, stdin);
	if (read == NULL)
		return;
	
	u32 end = 0;
	while (str[end] != '\n' && str[end] != '\0')
		end++;
	if (str[end] == '\n')
		str[end] = '\0';
	else {
		s32 ch;
		while ((ch = getchar()) != '\n' && ch != EOF)
			;
	}
}

Operand parse_num(const char *const numstr, char *errmsg)
{
	errno = 0;
	char *endptr = NULL;
	f64 val = strtold(numstr, &endptr);

	if (errno == ERANGE) {
		snprintf(errmsg, 255, "%s", strerror(errno));
		return (Operand){.f64v = val, .valid = false};
	}

	if (endptr == numstr) {
		snprintf(errmsg, 255, "No digits were found\n");
		return (Operand){.f64v = val, .valid = false};
	}

	if (*endptr != '\0')
		snprintf(errmsg, 255, "Further characters after number: \"%s\"\n", endptr);

	return (Operand){.f64v = val, .valid = true};
}

void handler_noop(char cmd)
{
	fprintf(stderr, "Unknown command: %c, no-op\n", cmd);
}

Operand command_handler(char cmd, Operand lhs, Operand rhs)
{
	calc_op op = dispatch[(unsigned char) cmd];
	if (op == NULL) {
		handler_noop(cmd);
		return (Operand){.f64v = 0, .valid = false};
	}
	return op(lhs, rhs);
}
