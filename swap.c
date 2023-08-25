#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number where the swap operation is performed.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp1, temp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;
	(*stack)->n = temp2;
	(*stack)->next->n = temp1;
}
