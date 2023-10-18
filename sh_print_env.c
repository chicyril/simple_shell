#include "sshell.h"

/**
 * print_env - print environment variables
*/
void print_env(void)
{
	int i = 0;

	for (; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], chr_count(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
