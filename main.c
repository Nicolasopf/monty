#include "monty.h"

/**
 * main - Starting point to check the file.
 * @argc: Arguments counter.
 * @argv: Arguments vectors.
 * Return: asdf
 */

int main(int argc, char *argv[])
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"nop", _nop},
		{NULL, NULL}
	};
	char *opcode = NULL;
	size_t buff_sz = 0;
	ssize_t line_sz = 0;
	unsigned int line_num = 0, i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	GBB.f1 = fopen(argv[1], "r");
	if (!GBB.f1)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_sz >= 0)
	{
		line_num++;
		line_sz = getline(&GBB.buffer, &buff_sz, GBB.f1);
		if (GBB.buffer)
		{
			GBB.buffer[strlen(GBB.buffer) - 1] = '\0';
			opcode = strtok(GBB.buffer, " ");
			if (opcode)
				for (i = 0; ops[i].opcode; i++)
					if (strcmp(opcode, ops[i].opcode) == 0)
					{
						ops[i].f(&GBB.stack, line_num);
						break;
					}
		}
	if (!ops[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		free_all();
		exit(EXIT_FAILURE);
	}
	}
	free_all();
	return (0);
}
