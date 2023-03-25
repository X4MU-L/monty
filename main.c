#include "monty.h"

/**
 * main - entry point
 * @argc: number of argument passed to the function call
 * @argv: pointer to array of argument(s) passed
 *
 * Description: takes in a files and execute the monty code in it
 * Return: 0 on success else exit with error code
 */
op_t op = OP_INIT;
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	size_t line_num = 1, len = 0, i = 0;
	ssize_t read;
	FILE *fd;
	char *line = NULL, *func;

	check_args(argc, argv);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (; (read = getline(&line, &len, fd)) != -1; line_num++)
	{
		i = 0;
		while (is_delim(line[i]) && line[i] != '\n')
			i++;
		if (line[i] != '\n' && line[i])
		{
			func = get_opcodes(line + i);
			if (!func)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free(line);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
			if (run_opcode(&stack, func, line_num) != 0)
			{
				free(func);
				exit_free(stack, line, fd);
				set_op();
				exit(EXIT_FAILURE);
			}
			free(func);
		}
		set_op();
	}
	return (exit_free(stack, line, fd));
}
