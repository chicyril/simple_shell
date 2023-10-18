#include "sshell.h"
/**
 * geten_var - get the value of a specified environmental variable
 * @var: the name of the variable
 *
 * Return: a string containing the value
 **/
char *geten_var(char *var)
{
	char *temp = NULL, *tok = NULL, *val = NULL;
	int i = 0;

	for (; environ[i]; i++)
	{
		temp = dup_str(environ[i]);
		tok = strtotok(temp, "=");
		if (!tok)
			return (NULL);
		if (isamatch(var, tok))
		{
			val = mvpstr(environ[i], "=");
			val++;
		}
		free(temp);
		temp = NULL;
		if (val)
			break;
	}
	return (val);
}
