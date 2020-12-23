#include "monty.h"

/**
 * _pint - Prints the node in the stack.
 * @stack: head of the list.
 * @line_number: Num of the line.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
