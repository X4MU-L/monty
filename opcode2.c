#include "monty.h"


/**
 * swap_opcode - swap top of the stack
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void swap_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int tmp_int;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
		       line_num);
		op.error = 1;
		return;
	}

	tmp_int = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp_int;
}

/**
 * swap_opcode - swap top of the stack
 * @stack: pointer to node stack
 * @line_num: line number of command
 * Return: void
 */

void add_opcode(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
		       line_num);
		op.error = 1;
		return;
	}

	temp->next->n = temp->n + temp->next->n;
	*stack = temp->next;
	free(temp);
}


/**
 * get_opcodes - gets the opcode an argument where necessary
 * @line: a string of chars terminated with a newline char
 *
 * Description: Takes in a string of char terminsted by a newline
 * parses then into instruction and argument
 * Return: return a pointer to the instruction or NULL on failure
 */
char *get_opcodes(char *line)
{
	int i = 0, k = 0, temp_i = 0;
	char *func, *pcode;

	while (!is_delim(line[i]) && line[i] != 10)
		i++;

	func = malloc(sizeof(char) * i + 1);
	if (func == NULL)
		return (NULL);
	i = 0;
	while (!is_delim(line[i]) && line[i] != 10)
	{
		func[i] = line[i];
		i++;
	}

	func[i] = '\0';
	while (is_delim(line[i]) && line[i] != 10)
		i++;
	if (line[i] == 10)
		return (func);

	temp_i = i;
	while (!is_delim(line[i]) && line[i] != 10)
		i++;
	i -= temp_i;

	pcode = malloc(sizeof(char) * i + 1);
	if (pcode == NULL)
	{
		free(func);
		return (NULL);
	}
	while (k < i)
		pcode[k++] = line[temp_i++];
	pcode[k] = '\0';
	op.value = pcode;
	return (func);
}
