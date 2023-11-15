#include "monty.h"

/*definition of global variable */
stack_t *stack = NULL;

/**
 * main - main entry point of program
 * 	gets command line arguments
 * @argc: argument count
 * @argv: argumnent vector (an array)
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_file(argv[1]);
	return (0);
}
