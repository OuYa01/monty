#include "monty.h"

/**
 * print - function that print all the element that pushed to the stack
 *
 * @stack: pointer that point to the stack
 * @line_number: count number of lines
 *
 * Return: nothing
 *
 */
void print(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

