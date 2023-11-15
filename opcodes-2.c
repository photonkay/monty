#include "monty.h"

/**
 * mul - multiplies the last two elements
 * @stack: header of stack linked list
 * @line_number: Executing line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * mod - computes the rest of the division of the
 * 	second top by the top element
 * @stack: linked list
 * @line_number: line number
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack_t stack
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value >127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	putchar(ascii_value);
	putchar('\n');
}

/**
 * pstr - prints the string at the top of the stack
 * @stack: stack to consider
 * @line_number: line number of command
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
