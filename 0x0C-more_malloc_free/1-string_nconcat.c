#include <stdlib.h>
/**
 * _strlen - Returnns the length of a string
 * @s: Pointer to a characher
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

/**
 * string_nconcat - Concatenates two strings
 * @s1: Point to the first string
 * @s2: Point to the second string
 * @n: Number of bytes to be concatenated from s2
 *
 * Return: Returns a pointer to the allocated memory
 *         NULL if fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i, len1, len2;

	if (s1 == NULL && s2 == NULL)
		return ("");
	ptr = s1;
	len1 = _strlen(ptr);
	ptr = s2;
	len2 = _strlen(ptr);
	len2 = n > len2 ? len2 : n;

	ptr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	for (i = 0; i < len1 + len2; i++)
	{
		if (i < len1)
			ptr[i] = s1[i];
		else
			ptr[i] = s2[i - len1];
	}
	ptr[i] = '\0';
	return (ptr);
}
