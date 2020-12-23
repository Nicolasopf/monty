#include "monty.h"

/**
 * main - Starting point to check the file.
 * @argc: Arguments counter.
 * @argv: Arguments vectors.
 * Return: asdf
 */

int main(int argc, char *argv[])
{
	size_t buff_sz = 0;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	GBB.f1 = fopen(argv[1], "r");
	if (!GBB.f1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&GBB.buffer, &buff_sz, GBB.f1) != EOF && ++line_num)
		if (GBB.buffer)
		{
			GBB.buffer[strlen(GBB.buffer) - 1] = '\0';
			get_fun(line_num);
		}
	free_all();
	return (0);
}
