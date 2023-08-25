#include "monty.h"
/**
 * push - function that push numbers to the stack
 *
 * @stack: a pointer point to stack
 * @data: the data to be pushed
 * @line_number: tracker of lines
 *
 * Return: nothing
 */
void push(stack_t **stack, int data, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!stack)
	{
		fprintf(stderr, "L%d: stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (newNode == NULL)
	{
		printf("stack overflow.");
		exit(1);
	}
	newNode->n = data;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
