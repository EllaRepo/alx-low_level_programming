#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory
 *           which contains a copy of the string given as a parameter
 * @str: Pointing to the string
 *
 * Return: Returns a pointer to a newly allocated space
 *         NULL if str=NULL or insufficient memory was available
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i, size;

	if (str == NULL)
		return (NULL);
	size = i = 0;
	ptr = str;
	while (ptr[size] != '\0')
		size++;
	size += 1;
	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}

	return (ptr);
}
