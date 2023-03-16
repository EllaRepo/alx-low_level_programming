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
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (old_size == new_size)
		return (ptr);
	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}
