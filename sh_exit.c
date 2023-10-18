#include "sshell.h"

/**
 * sh_exit - exits the shell
 * @cmd_toks: command line argument
 *
 * Return: -1 in case of error
 */
int sh_exit(char **cmd_toks)
{
	int status = 0;

	if (cmd_toks[1])
	{
		status = sh_atoi(cmd_toks[1]);
		if (status == -1)
			return (-1);
	}
	squash(cmd_toks);
	exit(status);
}
