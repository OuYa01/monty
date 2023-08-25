#include "monty.h"

/**
 * peek - Returns the value of the top element of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * Return: Value of the top element.
 */

int peek(const stack_t *stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (stack->n);
}
