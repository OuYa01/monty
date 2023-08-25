#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

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
	char *choice;
	int data;
	unsigned int line_number = 1;
	FILE *file;
	size_t len = 0;
	char *line = NULL;
	char *argstr;

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
	while (getline(&line, &len, file) != -1)
	{
		choice = strtok(line, " \t\n");
		if (choice == NULL || choice[0] == '#')
		{
			line_number++;
			continue;
		}
		if (strcmp(choice, "push") == 0)
		{
			argstr = strtok(NULL, " \t\n");
			if (!argstr)
			{
				printf("L%d: usage: push integer\n", line_number);
				fclose(file);
				free(line);
				free_stack(&stack);
				return (EXIT_FAILURE);
			}
			data = atoi(argstr);
			push(&stack, data, line_number);
		}
		else if (strcmp(choice, "pall") == 0)
		{
			print(&stack, line_number);
		}
		else if (strcmp(choice, "pint") == 0)
		{
			printf("%d\n", peek(stack));
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, choice);
			fclose(file);
			free(line);
			free_stack(&stack);
			return (EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (0);
}
