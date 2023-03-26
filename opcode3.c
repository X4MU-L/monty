#include "monty.h"


/**
 * div_opcode - divides the second top data of the stack by the top
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void div_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
		       line_num);
		op.error = 1;
		return;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		op.error = 1;
		return;
	}

	temp->next->n /= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * mul_opcode - multiplies the second top data of the stack by the top
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void mul_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
		       line_num);
		op.error = 1;
		return;
	}

	temp->next->n *= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * mod_opcode - mods the second top data of the stack by the top
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void mod_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
		       line_num);
		op.error = 1;
		return;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		op.error = 1;
		return;
	}

	temp->next->n %= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * pchar_opcode - prints the char at the top of the stack
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void pchar_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
		       line_num);
		op.error = 1;
		return;
	}
	if (!is_printable_ascii(temp->n))
	{
		fprintf(stderr, "L%d: cant't pchar, value out of range\n",
			line_num);
		op.error = 1;
		return;
	}

	printf("%c\n", temp->n);
}
