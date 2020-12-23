#include "monty.h"

/**
 * _sub - Substract data from top two nodes.
 * @stack: head.
 * @line_number: num of line.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n = (*stack)->next->n - (*stack)->n;
	(*stack) = tmp->next;
	free(tmp);
}

/**
 * _div - Divide data from the top two nodes.
 * @stack: head.
 * @line_number: num of line.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n = (*stack)->next->n / (*stack)->n;
	(*stack) = tmp->next;
	free(tmp);
}

/**
 * _mul - Multiply from the top two nodes.
 * @stack: head.
 * @line_number: Num of line.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n = (*stack)->next->n * (*stack)->n;
	(*stack) = tmp->next;
	free(tmp);
}

/**
 * _mod - Get the module from the top two nodes.
 * @stack: head.
 * @line_number: num line.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->next->n = (*stack)->next->n % (*stack)->n;
	(*stack) = tmp->next;
	free(tmp);
}
