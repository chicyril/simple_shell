#include "sshell.h"

/**
 * gettokens - get tokens (words) from a string
 * @str: the string to tokenize
 * @delim: the delimeter seperating each token
 *
 * Return: an array of tokens
 **/
char **gettokens(char *str, const char *delim)
{
	char **toks = NULL, *tok = NULL, *temp = NULL;
	int i, tok_count = 0;

	temp = dup_str(str);
	if (!str || !temp)
		return (NULL);
	tok_count = gettok_count(temp, delim);
	toks = malloc(sizeof(char *) * ((tok_count) + 1));
	if (!toks)
		return (NULL);
	tok = strtotok(temp, delim);
	for (i = 0; tok; i++)
	{
		toks[i] = NULL;
		toks[i] = dup_str(tok);
		if (!toks[i])
		{
			squash(toks);
			free(temp);
			return (NULL);
		}
		tok = strtotok(NULL, delim);
	}
	toks[i] = NULL;
	free(temp);
	return (toks);
}
