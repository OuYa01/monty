#include "monty.h"

/**
 * free_stack - Frees the entire stack.
 *
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
	*stack = NULL;
}
