/**
  * @file main.c
  * @brief Entry point of calculator
*/
/* vim: set noet ts=4 sw=4: */
/* include files */
#include <stdio.h>

#include "app.h"

/* macro definitions */

/* type definitions */

/* variable declarations */

/* function prototypes */

/* function definitions */
int main(void)
{
	for (;;) {
		char op[2] = {0,};
		char slhs[21] = {0,}; // s64 can hold 20 digits for unsigned value
		char srhs[21] = {0,}; 

		prompt("Select OP ['+' '-' '*' '/' '!' '#']: ");
		getline(op, countof(op));
		prompt("Enter lhs number: ");
		getline(slhs, countof(slhs));
		prompt("Enter rhs number: ");
		getline(srhs, countof(srhs));

		char errmsg[256] = {0,};
		Operand lhs = parse_num(slhs, errmsg);
		Operand rhs = parse_num(srhs, errmsg);

		if (lhs.valid == false || (rhs.valid == false && (*op != '!' && *op != '#'))) {
			fprintf(stderr, "%s", errmsg);
			continue;
		}

		Operand ret = command_handler(*op, lhs, rhs);
		fprintf(stdout,"result: %Lf, valid: %s\n", ret.f64v, (ret.valid == true) ? "yes" : "no");
	}
}
