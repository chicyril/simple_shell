#include "sshell.h"

/**
 * sh_atoi - converts string digits to integer
 * @s: string to convert
 *
 * Return: integer
 */
int sh_atoi(char *s)
{
	int i = 0, ret = 0, sign = 1;

	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		ret = ret * 10 + (s[i] - '0');
		i++;
	}
	return (sign * ret);
}
