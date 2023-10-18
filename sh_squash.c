#include "sshell.h"

/**
 * squash - free the internal pointers of an array of pointers
 * @str: array of pointers
 **/
void squash(char **str)
{
	int i = 0;


	if (!(str[i]))
		i++;
	for (; str[i]; i++)
		free(str[i]);
	free(str);
}
