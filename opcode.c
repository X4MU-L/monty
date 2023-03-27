#include "monty.h"

/**
 * pint_opcode - prints the first data on the stack
 * @stack: a  pointer to a doubly linked list - (the stack)
 * @line_num: the line number of the function being called
 * from the monty file
 *
 * Return: void
 */

void pint_opcode(stack_t **stack, unsigned int line_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		op.error = 1;
		return;
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop_opcode - pop the first node on the stack
 * @stack: a  pointer to a doubly linked list - (the stack)
 * @line_num: the line number of the function being called
 * from the monty file
 *
 * Return: void
 */

void pop_opcode(stack_t **stack, unsigned int line_num)
{
	if (!remove_node_start(stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		op.error = 1;
		return;
	}
}

/**
 * print_opcode - print the data of nodes on the stack
 * @stack: a  pointer to a doubly linked list - (the stack)
 * @line_num: the line number of the function being called
 * from the monty file
 *
 * Return: void
 */

void print_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	(void) line_num;

	if (!stack || !*stack)
		return;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push_opcode - push a node on the stack
 * @stack: a  pointer to a doubly linked list - (the stack)
 * @line_num: the line number of the function being called
 * from the monty file
 *
 * Return: void
 */

void push_opcode(stack_t **stack, unsigned int line_num)
{
	char *n;

	n = op.value;
	if (!is_numbers(n) || !n)
	{
		if (n)
			free(n);
		int_usage_error(line_num);
		return;
	}
	if (op.is_stack)
	{
		if (add_node_start(stack, atoi(n)) == NULL)
		{
			free(n);
			malloc_error();
			return;
		}
	}
	else
	{
		if (add_node_end(stack, atoi(n)) == NULL)
		{
			free(n);
			malloc_error();
			return;
		}
	}
	free(n);
	op.value = NULL;
}

/**
 * run_opcode - get opcode func and run it accoring to instrction
 * @stack: a  pointer to a doubly linked list - (the stack)
 * @line_num: the line number of the function being called
 * from the monty file
 * @func: insruction to run
 *
 * Description: The function takes in a pointer to an instruction
 * e.g "push" searches for its eqivalent function and run it
 * Return: 0 success -1 on failure
 */

int run_opcode(stack_t **stack, char *func, unsigned int line_num)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", push_opcode},
		{"pop", pop_opcode},
		{"pall", print_opcode},
		{"pint", pint_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"nop", nop_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{"stack", stack_opcode},
		{"queue", queue_opcode},
		{NULL, NULL},
	};

	for (i = 0; instruction[i].f != NULL; i++)
	{
		if (_strcmp(func, instruction[i].opcode) == 0)
		{
			instruction[i].f(stack, line_num);
			if (op.error)
				return (-1);
			return (0);
		}
	}
	if (instruction[i].f == NULL)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num,
			func);
	return (-1);

}
