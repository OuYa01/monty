#include "monty.h"

/**
 * peek - Returns the value of the top element of the stack.
 *
 * @stack: Pointer to the top of the stack.
 * Return: Value of the top element.
 */

int peek(const stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error: Stack is empty\n");
		exit(EXIT_FAILURE);
	}
	return (stack->n);
}
