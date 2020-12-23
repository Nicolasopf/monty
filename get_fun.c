#include "monty.h"

/**
 * get_fun - get the proper function.
 * @line_number: Num of the line.
 */

void get_fun(unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"nop", _nop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"pop", _pop},
		{NULL, NULL}
	};
	char *opcode;
	unsigned int i = 0;

	opcode = strtok(GBB.buffer, " ");
	if (opcode)
		for (i = 0; ops[i].opcode; i++)
			if (strcmp(opcode, ops[i].opcode) == 0)
			{
				ops[i].f(&GBB.stack, line_number);
				break;
			}
	if (!ops[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
		free_all();
		exit(EXIT_FAILURE);
	}
}
