#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with a call to malloc
 * @old_size: The size in bytes, of the allocated space for ptr
 * @new_size: The new size, in bytes of the new memory block
 *
 * Return: Returns a pointer to the newly created memory block
 *         NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new;
	char *ol, *nw;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
		{
			free(new);
			return (NULL);
		}
		return (new);
	}
	new = malloc(new_size);
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new_size = old_size > new_size ? new_size : old_size;
	ol = ptr, nw = new;
	for (i = 0; i < new_size; i++)
		nw[i] = ol[i];
	free(ptr);
	return (new);
}
