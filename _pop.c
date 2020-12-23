#include "monty.h"

/**
 * _pop - add the two top nodes.
 * @stack: head of the list.
 * @line_number: Num of the line.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	dlistint_t *tmp = stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	*stack = tmp->next;
	free(tmp);
}
