#include "monty.h"

/**
 * run_monty - runs a monty interpreter
 * @fd: pointer to an open file descriptor
 * Return: (EXIT_SUCCESS) on success else (EXIT_SUCCESS)
 */

int run_monty(FILE* fd)
{
	stack_t *stack = NULL;
	size_t line_num = 1, len = 0, i = 0;
	ssize_t read;
	char *line = NULL, *func;

	for (; (read = getline(&line, &len, fd)) != -1; line_num++)
	{
		i = 0;
		while (is_delim(line[i]) && line[i] != '\n')
			i++;
		if (!is_comment_or_empty(line[i]))
		{
			func = get_opcodes(line + i);
			if (!func)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free(line);
				fclose(fd);
				return (EXIT_FAILURE);
			}
			if (run_opcode(&stack, func, line_num) != 0)
			{
				free(func);
				exit_free(stack, line, fd);
				set_op();
				return (EXIT_FAILURE);
			}
			free(func);
			set_op();
		}
	}
	return (exit_free(stack, line, fd));
}
/**
 * set_op - resets the op struct
 * Return: void
 */
void set_op(void)
{
	if (op.value)
		free(op.value);
	op.value = NULL;
	op.error = 0;
}

int is_comment_or_empty(char c)
{
	char *var = "#\n";
	int i = 0;

	while (var[i])
	{
		if (c == var[i])
			return (1);
		i++;
	}
	return (0);
}
