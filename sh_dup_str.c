#include "sshell.h"
/**
 * dup_str - duplicate a string
 * @str: the string to duplicate
 *
 * Return: a pointer to the new(duplicate) string
 **/
char *dup_str(char *str)
{
	char *dup = NULL;
	int i = 0;


	if (!str)
		return (NULL);
	dup = malloc(chr_count(str) + 1);
	if (!dup)
		return (NULL);
	for (; str[i]; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
