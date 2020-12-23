#include "monty.h"

/**
 * _swap - Swap data from two nodes.
 * @stack: head of the list.
 * @line_number: Num of the line.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int data = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	data = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = data;
}
