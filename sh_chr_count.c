#include "sshell.h"

/**
 * chr_count - count the number of characters in a string
 * @str: the string
 *
 * Return: the number of characters counted
 **/
int chr_count(char *str)
{
	int count = 0;

	for (; str[count]; count++)
		;
	return (count);
}
