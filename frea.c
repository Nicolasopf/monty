#include "monty.h"

/**
 * free_all - Free everything!
 */

void free_all(void)
{
	stack_t *tmp = GBB.stack;

	free(GBB.buffer);
	while (GBB.stack)
	{
		tmp = GBB.stack;
		GBB.stack = GBB.stack->next;
		free(tmp);
	}
	fclose(GBB.f1);
}
