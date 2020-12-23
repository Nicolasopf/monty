#include "monty.h"

/**
 * _push - Push to the head of a linked list.
 * @stack: head pointer.
 * @line_number: Num of the line.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *data;
	stack_t *new;

	data = strtok(NULL, " ");
	if (isdigit(atoi(data)) != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(data);
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	new->prev = NULL;
	*stack = new;
}
