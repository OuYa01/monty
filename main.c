#include "monty.h"


/**
 * main - Entry point of the programme
 *
 * @argc: counter of args
 * @argv: args
 *
 * Return: 0 if scc
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char choice[20];
	int data;
	unsigned int line_number = 1;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error cant open file\n");
		return (EXIT_FAILURE);
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
