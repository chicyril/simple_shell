#include "sshell.h"
/**
 * isbiutils - check if the entered command is shell builtin
 * @cmd_toks: address of a pointer to name of the command
 *
 * Return: true if is a builtin command, else false
 **/
bool isbiutils(char **cmd_toks)
{
	if (isamatch("env", cmd_toks[0]) || isamatch("printenv", cmd_toks[0]))
	{
		if (!cmd_toks[1])
			print_env();
		return (true);
	}
	if (isamatch("exit", cmd_toks[0]))
	{
		sh_exit(cmd_toks);
		write(STDERR_FILENO, "Illegal exit number!\n", 21);
		return (true);
	}
	return (false);
}
