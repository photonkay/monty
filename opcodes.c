#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: doubly linked list
 * @line_number: line number of code executing
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token = strtok(NULL, " \t\n");
	int value = atoi(token);
	stack_t *new_node = malloc(sizeof(stack_t));
	int i;

	if (!token)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

    for (i = 0; token[i] != '\0'; i++)
    {
        if (!isdigit(token[i]))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            free_stack();
            exit(EXIT_FAILURE);
        }
    }

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all element in stack
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * div_op - divides the second top element of the stack by the top element
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zeros\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
