#include "monty.h"


/**
 * usage_error - prints the the STDERR_FILENO usage error
 * Return: always (EXIT_FAILURE)
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_error - prints the the STDERR_FILENO file error
 * @file: filename to open
 * Return: always (EXIT_FAILURE)
 */
int file_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints the the STDERR_FILENO malloc error
 * Return: void
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	op.error = 1;
	op.value = NULL;
}

/**
 * int_usage_error - prints the the STDERR_FILENO int error
 * @line_num: line number at which the error occured
 * Return: void
 */
void int_usage_error(unsigned int line_num)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_num);
	op.error = 1;
	op.value = NULL;
}


