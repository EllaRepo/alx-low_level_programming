#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: Pointing to the first string
 * @s2: Pointing to the second string
 *
 * Return: Returns a pointer to a newly allocated space
 *         NULL if s1=s2=NULL or insufficient memory was available
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr;
	unsigned int i, j, cnt;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	cnt = i = j = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
			i++;
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		j++;
	}
	ptr = malloc(sizeof(char) * (i + j + 1));
	if (ptr == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		for (cnt = 0; s1[cnt] != '\0'; cnt++)
			ptr[cnt] = s1[cnt];
	}
	if (s2 != NULL)
	{
		for (i = 0; s2[i] != '\0'; i++, cnt++)
		ptr[cnt] = s2[i];
	}
	ptr[cnt] = '\0';

	return (ptr);
}
