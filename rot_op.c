#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: stack to rotate
 * @line_number: command line number
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;
	stack_t *last;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		last = *stack;

		while (last->next)
			last = last->next;
		*stack = second;
		second->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next)
			last = last->next;

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
