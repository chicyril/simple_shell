#include "sshell.h"

/**
 * isamatch - compares two strings to see if they are the same.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: true if they are the same or false otherwise
 **/
bool isamatch(char *str1, char *str2)
{
	int len1 = 0, len2 = 0;


	if (!str1 || !str2 || (chr_count(str1) != chr_count(str2)))
		return (false);
	for (; str1[len1] && str2[len2]; len1++, len2++)
	{
		if (str1[len1] != str2[len2])
			return (false);
	}
	return (true);
}
