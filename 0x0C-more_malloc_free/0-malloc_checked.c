#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc
 * @b: Size of memory
 *
 * Return: Returns a pointer to the allocated memory
 *         '98' if fails
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		free(ptr);
		exit(98);
	}

	return (ptr);
}
