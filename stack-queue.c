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
 * reverse_stack - reverses the stack order
 * @stack: stack to reverse
 * Return: void
 */
void reverse_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *prev = NULL;
	stack_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	*stack = prev;
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
		last = front;
		while (last->next)
			last = last->next;

		reverse_stack(stack);
		*stack = front->next;
		if (*stack)
			(*stack)->prev = NULL;

		if (last != front)
		{
			last->next = front;
			front->prev = last;
		}

		front->next = NULL;
		if (*stack)
			(*stack)->prev = front;
		else
			*stack = front;
	}
}
