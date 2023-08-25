#include "monty.h"


/**
 * main - Entry point of the programme
 *
 * Return: 0 if scc
 */
int main(void)
{
	stack_t *stack = NULL;
	char choice[20];
	int data;
	unsigned int line_number = 1;
	FILE *file = fopen("bytecodes/00.m", "r");

	if (file == NULL)
	{
		printf("Error");
		return (1);
	}
	while (fscanf(file, "%s", choice) != EOF)
	{
		if (strcmp(choice, "push") == 0)
		{
			if (fscanf(file, "%d", &data) != 1)
			{
				printf("L%d: usage: push integer\n", line_number);
				fclose(file);
				return (EXIT_FAILURE);
			}
			push(&stack, data, line_number);
		}
		else if (strcmp(choice, "pall") == 0)
		{
			print(&stack, line_number);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}
