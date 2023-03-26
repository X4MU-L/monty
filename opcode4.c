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
	stack_t *temp;
	int tmp_int;
	(void) line_num;

	temp = *stack;
	if (temp)
	{
		if (temp->next)
		{
			tmp_int = (*stack)->n;
			while (temp->next)
				temp = temp->next;

			(*stack)->n = temp->n;
			temp->n = tmp_int;
		}
	}
}
