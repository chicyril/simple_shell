#include "sshell.h"

/**
 * xxecute - run binaries or executable files
 * @cmd: addres of the name of the file
 */
void xxecute(char **cmd)
{
	pid_t pid;
	int wstatus;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: fork failed\n");
		return;
	}
	if (pid == 0)
	{
		execve(cmd[0], cmd, environ);
		perror(cmd[0]);
		exit(1);
	}
	if (pid > 0)
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			if (WIFSIGNALED(wstatus))
			{
				printf("child was killed by signal: [%d] ", WTERMSIG(wstatus));
				printf("exit_status: %d\n", WEXITSTATUS(wstatus));
			}
		}
	}
}
