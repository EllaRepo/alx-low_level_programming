#include <stdlib.h>

/**
 * create_array - Creates an array of chars, and
 *                initializes it with a specific char
 * @size: The size of the array
 * @c: The character the array will be initialized
 *
 * Return: A char pointer pointing to the array
 */
char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	if (size == 0)
		return (NULL);
	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = c;

	return (ptr);
}
