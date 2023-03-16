#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array, using malloc
 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Return: Returns a pointer to the allocated memory
 *         NULL if fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *c;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	c = ptr;
	for (i = 0; i < nmemb * size; i++)
		c[i] = 0x00;

	return (ptr);
}
