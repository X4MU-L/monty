#include "monty.h"
/**
 * _strlen - gets the length of a string
 * @s: pointer to a string to get length
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @str1: pointer to string
 * @str2: pointer to string
 * Return: return 0 if string matches else non zero
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++, str2++;
	}
	return (*str1 - *str2);
}

/**
 * is_digit - checks if a char is a digit
 * @c: char to check
 * Return: 1 if digit else 0
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * is_delim - checks if a char is a delimiter
 * @c: char to check
 * Return: 0 if not delimiter else 1
 */
int is_delim(const char c)
{
	int i = 0;
	char *delim = " \t";

	while (c != delim[i] && delim[i])
		i++;
	if (delim[i])
		return (1);
	return (0);
}
