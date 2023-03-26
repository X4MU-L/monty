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
