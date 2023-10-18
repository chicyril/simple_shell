#include "sshell.h"

/**
 * gettok_count - count the number of token (words) in a string
 * @str: the string containing the tokens
 * @delim: the characters separating each word
 *
 * Return: the number of tokens counted
 **/
int gettok_count(char *str, const char *delim)
{
	int tok_count = 0, i, j;
	bool istok = false, isdelim;

	for (i = 0; str[i]; i++)
	{
		isdelim = false;
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				isdelim = true;
				istok = false;
				break;
			}
		}
		if (!isdelim && !istok)
		{
			istok = true;
			tok_count++;
		}
	}
	return (tok_count);
}
