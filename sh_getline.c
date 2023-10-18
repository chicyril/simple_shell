#include "sshell.h"

/**
 * get_line - get a line of text from a file
 * @buffadr: address of a buffer to store the line of command
 * @buffsz: size of the buffer created for the command line
 * @fd: descriptor of the file from where to get the line of text
 *
 * Return: the number of characters read or -1 in case of error
 **/
ssize_t get_line(char **buffadr, size_t *buffsz, int fd)
{
	ssize_t rd_sz = 0, oldsz = 0, index = 0, retval = 0, i;
	int init = gl_vauto_init(buffadr, buffsz, fd);

	if (!init)
		return (-1);
	while (1)
	{
		rd_sz = read(fd, (*buffadr) + retval, (*buffsz) - 1 - (size_t)retval);
		if (rd_sz == -1)
			return (-1);
		if (rd_sz == 0)
		{
			(*buffadr)[retval] = '\0';
			break;
		}
		index = retval;
		retval += rd_sz;
		for (; index < retval; index++)
		{
			if ((*buffadr)[index] == '\n')
			{
				for (i = 1; (size_t)(index + i) < (*buffsz); i++)
					(*buffadr)[index + i] = '\0';
				return (index + 1);
			}
		}
		if ((size_t)retval >= (*buffsz) - 1)
		{
			oldsz = (*buffsz);
			*buffsz += DEFAULT_BUFFSIZE;
			*buffadr = buff_realloc((*buffadr), oldsz, *buffsz);
		}
	}
	if (!retval)
		retval = -1;
	return (retval);
}
