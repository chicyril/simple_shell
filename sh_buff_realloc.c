#include "sshell.h"
/**
 * buff_realloc - reallocate size of a buffer
 * @ptr: pointer to the buffer
 * @oldsz: old size of the buffer
 * @newsz: new size to be allocated
 *
 * Return: pointer to the new buffer on success
 **/
char *buff_realloc(char *ptr, size_t oldsz, size_t newsz)
{
	size_t i;
	char *newptr = NULL;

	if (newsz == 0)
	{
		free(ptr);
		return (NULL);
	}
	if ((!ptr) && newsz)
	{
		ptr = malloc(newsz);
		return (ptr);
	}
	if (newsz <= oldsz)
		return (ptr);
	newptr = malloc(newsz);
	if (!newptr)
		return (NULL);
	for (i = 0; i < oldsz; i++)
		newptr[i] = ptr[i];
	free(ptr);
	return (newptr);
}
