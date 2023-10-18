#include "sshell.h"

/**
 * isvalid - checks for a command's file or its full path
 * @cmd: the command's file or path
 *
 * Return: true if found, else - false
 **/
bool isvalid(char *cmd)
{
	struct stat s;

	if (cmd)
		if (stat(cmd, &s) == 0)
			return (true);
	return (false);
}
