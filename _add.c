#include "monty.h"

/**
 * _add - add the two top nodes.
 * @stack: head of the list.
 * @line_number: Num of the line.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	dlistint_t *tmp = stack;

	if (!(*stack) || !(*stack)>next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n = (*stack)->n + (*stack)->next->n;
	(*stack) = tmp->next;
	free(tmp);
}
