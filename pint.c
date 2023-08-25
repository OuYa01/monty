#include "monty.h"


int peek(const stack_t *stack)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Error: Stack is empty\n");
		exit(EXIT_FAILURE);
	}
	return stack->n;
}
