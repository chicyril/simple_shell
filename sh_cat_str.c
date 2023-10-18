#include "sshell.h"

/**
 * cat_str - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to a new string containing the concatenated string
 **/
char *cat_str(char *s1, char *s2)
{
	int j, indx = 0, l1 = chr_count(s1), l2 = chr_count(s2);
	char *new_str = NULL;


	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	new_str = malloc(sizeof(char) * (l1 + l2 + 1));
	for (j = 0; s1[j]; j++)
		new_str[indx++] = s1[j];
	for (j = 0; s2[j]; j++)
		new_str[indx++] = s2[j];
	new_str[indx] = '\0';
	return (new_str);
}
