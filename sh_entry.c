#include "sshell.h"

/**
 * main - entry of a simple shell program
 * @ac: number of arguments passed to the shell
 * @av: list of the arguments
 *
 * Return: the exit code of the shell program
 **/
int main(int ac, char **av)
{
	int tty = isatty(STDIN_FILENO);
	char *cmd_line = NULL, **cmd_toks = NULL;
	int rd_len = 0;
	(void)ac;

	while (1)
	{
		if (tty)
			write(STDOUT_FILENO, ">> ", 3);
		rd_len = read_cmd(&cmd_line);
		if (rd_len == -1)
			break;
		if (rd_len)
		{
			cmd_toks = gettokens(cmd_line, " \t\n");
			free(cmd_line);
			cmd_line = NULL;
			if (cmd_toks[0] && (*(cmd_toks[0])))
			{
				if (!(isbiutils(cmd_toks)))
				{
					if (isvalid(cmd_toks[0]))
						xxecute(cmd_toks);
					else if (isvalidpath(cmd_toks))
						xxecute(cmd_toks);
					else
						perror(av[0]);
				}
			}
			squash(cmd_toks);
			cmd_toks = NULL;
		}
		free(cmd_line);
		cmd_line = NULL;
		if (!tty)
			break;
	}
	return (0);
}
