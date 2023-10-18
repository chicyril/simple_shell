#include "sshell.h"

/**
 * chrstr - search for a character in a string of characters
 * @c: the character being searched for
 * @str: the string being searched
 *
 * Return: true if found, false otherwise
 **/
bool chrstr(char c, const char *str)
{
	int i = 0;


	while (str[i])
		if (c == str[i++])
			return (true);
	return (false);
}
