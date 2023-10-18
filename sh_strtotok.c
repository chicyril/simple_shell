#include "sshell.h"

/**
 * strtotok -  find tokens(words) in a string
 * @str: the string to tokenize
 * @delim: delimiters separating words in the string
 *
 * Return: a pointer to the token found after each calls or null
 **/
char *strtotok(char *str, const char *delim)
{
	static char *curr_pos;
	char *tok = NULL;


	if (delim)
	{
		if (str)
			curr_pos = str;
		if (curr_pos && *curr_pos)
		{
			while (*curr_pos && chr_instr(*curr_pos, delim))
				curr_pos++;
			if (*curr_pos)
			{
				tok = curr_pos;
				curr_pos = mvpstr(curr_pos, delim);
				if (*curr_pos)
				{
					curr_pos[0] = '\0';
					curr_pos++;
				}
				return (tok);
			}
		}
	}
	curr_pos = NULL;
	return (NULL);
}
