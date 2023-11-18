#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = (*stack)->next;
	free(top_node);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	/* Save the values of the top two elements */
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: doubly linked list
 * @line_number: line number
 * Return void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	/* Save the values of the top two elements */
	result = (*stack)->n + (*stack)->next->n;

	/* Pop the top element (remove it from the stack) */
	pop(stack, line_number);

	/* Update the new top element with the result */
	(*stack)->n = result;
}

/**
 * sub - subtracts the top element from the second top
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;

	pop(stack, line_number);
	if (*stack)
		(*stack)->n = result;
	(*stack)->n = result;
}
