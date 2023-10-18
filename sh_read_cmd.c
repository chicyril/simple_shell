#include "sshell.h"

/**
 * read_cmd - read command line from the user
 * @cmd_line: address of buffer to store the command line
 *
 * Return: the number of character read
 **/
int read_cmd(char **cmd_line)
{
	size_t line_len = 0;
	int rd_len = 0;


	rd_len = get_line(cmd_line, &line_len, STDIN_FILENO);
	if (rd_len == -1)
	{
		free(*cmd_line);
		write(STDOUT_FILENO, "\n", 1);
		return (-1);
	}
	return (rd_len - 1);
}
