#include "monty.h"

op_t op = OP_INIT;
/**
 * main - entry point
 * @argc: number of argument passed to the function call
 * @argv: pointer to array of argument(s) passed
 *
 * Description: takes in a files and execute the monty code in it
 * Return: (EXIT_SUCCESS) on success else (EXIT_FAILURE)
 */

int main(int argc, char **argv)
{
	FILE *fd;

	if (argc != 2)
		return (usage_error());
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (file_open_error(argv[1]));

	return (run_monty(fd));
}
