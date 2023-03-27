#include "monty.h"

/**
 * rotl_opcode - takes the first not to last and second to first
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void rotl_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void) line_num;

	temp = *stack;
	if (temp)
	{
		if (temp->next)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = *stack;
			*stack = (*stack)->next;
			temp->next->next = NULL;
		}
	}
}

/**
 * rotr_opcode - takes the first not to last and second to first
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void rotr_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *bottom, *top;
	(void) line_num;

	bottom = top = *stack;
	if (bottom)
	{
		if (bottom->next)
		{
			*stack = bottom->next;
			while (bottom->next)
				bottom = bottom->next;
			bottom->next = top;
			top->prev = bottom;
			top->next = NULL;
		}
	}
}

/**
 * stack_opcode - sets the node to a LIFO (stack)
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void stack_opcode(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	op.is_stack = 1;
}

/**
 * queue_opcode - sets the node to a FILO (queue)
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void queue_opcode(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	op.is_stack = 0;
}
