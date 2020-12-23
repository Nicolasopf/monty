#include "monty.h"

/**
 * _pall - Prints all nodes.
 * @stack: head of the list.
 * @line_number: Num of the line.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
