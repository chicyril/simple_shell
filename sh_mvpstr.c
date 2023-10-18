#include "sshell.h"

/**
 * mvpstr - move a pointer to a string, to the first occurrence of any
 * delimiter character in the string
 * @str: the string pointer
 * @delim: a string containing delimiters
 *
 * Return: pointer to the first occurrence of the delimiter in the string
 **/
char *mvpstr(char *str, const char *delim)
{
	for (; *str; str++)
		if (chrstr(*str, delim))
			break;
	return (str);
}
