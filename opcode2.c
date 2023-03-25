#include "monty.h"


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
