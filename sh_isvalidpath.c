#include "sshell.h"

/**
 * isvalidpath - append a command to a path and check for it
 * @cmd: pointer to the command name
 *
 * Return: true if found, else, false
 **/
bool isvalidpath(char **cmd)
{
	char *path = geten_var("PATH");
	char *copypath, *dir = NULL, *dcmd = NULL;
	int j, i, len = 0;

	copypath = dup_str(path);
	if (!(cmd) || !copypath)
		return (false);
	dir = strtotok(copypath, ":");
	while (dir)
	{
		i = 0;
		len = (chr_count(dir) + chr_count(cmd[0]) + 2);
		dcmd = malloc(sizeof(char) * len);
		if (!dcmd)
		{
			perror("failed to check path\n");
			return (false);
		}
		for (j = 0; dir[j]; j++)
			dcmd[i++] = dir[j];
		dcmd[i++] = '/';
		for (j = 0; (cmd[0])[j]; j++)
			dcmd[i++] = (cmd[0])[j];
		dcmd[i] = '\0';
		if (isvalid(dcmd))
		{
			free(cmd[0]);
			cmd[0] = dcmd;
			free(copypath);
			copypath = NULL;
			return (true);
		}
		free(dcmd);
		dcmd = NULL;
		dir = strtotok(NULL, ":");
	}
	free(copypath);
	free(dcmd);
	copypath = NULL;
	return (false);
}
