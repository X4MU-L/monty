#include "monty.h"
/**
 * check_args - checks if correct arguments were passed
 * to the function call
 * @argc: number of arguments passed to the function
 * @argv: pointer to the array of arguments passed
 * Return: 0 on success else exit with failure code
 */
int check_args(int argc, char **argv)
{
	struct stat buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], &buffer) != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * set_op - resets the op struct
 *
 * Return: void
 */
void set_op(void)
{
	if (op.value)
		free(op.value);
	op.value = NULL;
	op.error = 0;
	op.overflow = 0;
	op.underflow = 0;
}
