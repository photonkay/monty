#include "monty.h"

/**
 * stack_op - sets the format of the data to a stack
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	/* no code */
	/* since the program is already in stack format */
}

/**
 * queue_op - sets the format to a queue
 * @stack: doubly linked list
 * @line_number: line number
 * Return: void
*/
void queue_op(stack_t **stack, unsigned int line_number)
{
	stack_t *front;
	stack_t *last;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		front = *stack;
		last = *stack;
		while (last->next)
			last = last->next;

		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = front;
		front->prev = last;
		front->next = NULL;
	}
}
