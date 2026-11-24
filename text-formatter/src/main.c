/**
  * @file main.c
  * @brief text-converter entry point
  */
/* vim: set noet ts=4 sw=4: */
/* include files */
#include "stdio.h"

#include "app.h"

/* macro definitions */
#define INPUT_SZ (size_t)1024*1024 // 1MB

/* type definitions */

/* variable declarations */

/* function prototypes */

/* function definitions */
int main(void)
{
	for (;;) {
		char op[2] = {0,};
		char input[INPUT_SZ] = {0,};
		size_t input_len = INPUT_SZ;
		size_t op_len = countof(op);

		prompt("Input text: ");
		getline(input, &input_len);
		prompt("Transform to lower-case [_] or upper-case [^]: ");
		getline(op, &op_len);
		
		const char * res = command_handler(*op, input, input_len);
		fprintf(stdout, "\n%s\n", res);
	}
}
