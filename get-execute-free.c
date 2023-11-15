#include "monty.h"
#include <stdio.h>

/* global variable array */
instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", div_op},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", stack_op},
	{"queue", queue_op},
	{NULL, NULL}
};

/**
 * get_instruction - gets the opcode instruction to execute
 * @opcode - the opcode to execute
 * Return: the opcode if found in the array
 */
void *get_instruction(char *opcode)
{
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			return (&opcodes[i]);
		}
		i++;
	}

	return (NULL);
}

/**
 * execute_file - executes the file using the opcode received
 * @file: name of file to execute
 * Return: void
 */
void execute_file(char *file_path)
{
	FILE *file = fopen(file_path, "r");
	char line[MAX_LENGTH];
	unsigned int line_number = 0;
	char *opcode;
	instruction_t *instruction;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		
		if (opcode && opcode[0] != '#')
		{
			instruction = get_instruction(opcode);

			if (instruction)
			{
				instruction->f(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free_stack();
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	free_stack();
}

/**
 * free_stack - frees a dlistint_t list.
 * 
 * Return: void
 */
void free_stack(void)
{
	stack_t *current = stack;

	while (current)
	{
		stack_t *next = current->next;
		free(current);
		current = next;
	}

	stack = NULL;
}
