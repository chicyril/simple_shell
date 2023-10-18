#include"sshell.h"

/**
 * gl_vauto_init - checks / initialize auto variables for the get_line function
 * @buffadr: address of a buffer to store the line of command
 * @buffsz: size of the buffer created for the command line
 * @fd: descriptor of the file from where to get the line of text
 *
 * Return: 1 if all good, else 0
 **/
int gl_vauto_init(char **buffadr, size_t *buffsz, int fd)
{
	int check_fd = fcntl(fd, F_GETFD);

	if (check_fd == -1)
	{
		perror("Error getting file descriptor.");
		return (0);
	}
	if (!(*buffadr))
	{
		if (!(*buffsz))
			*buffsz = DEFAULT_BUFFSIZE;
		*buffadr = (char *)malloc((*buffsz));
		if (!(*buffadr))
			return (0);
	}
	return (1);
}
