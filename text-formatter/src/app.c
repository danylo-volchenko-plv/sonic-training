/**
  * @file
  * @brief
  */
/* vim: set noet ts=4 sw=4: */
/* include files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
/* macro definitions */

/* type definitions */

/* variable declarations */
static const convfn dispatch[256] = {
	['^'] = toupper_,
	['_'] = tolower_,
};

/* function prototypes */

/* function definitions */

void prompt(const char *const str)
{
	fprintf(stdout, "%s", str);
	fflush(stdout);
}

void getline(char *str, size_t *len)
{
	const char *read = fgets(str, *len, stdin);
	if (read == NULL)
		return;
	
	size_t end = 0;
	while (str[end] != '\n' && str[end] != '\0')
		end++;
	if (str[end] == '\n')
		str[end] = '\0';
	else {
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF)
			;
	}

	*len = end;
}

void handler_noop(char cmd)
{
	fprintf(stderr, "Unknown command: %c, no-op\n", cmd);
}

char *command_handler(char cmd, char *str, size_t len)
{
	convfn op = dispatch[(unsigned char) cmd];
	if (op == NULL) {
		handler_noop(cmd);
		return NULL;
	}
	return convert(str, len, op);
}
