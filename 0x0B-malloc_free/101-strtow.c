#include <stdlib.h>
/**
 * splitw - Splits a string into words
 * @sw: Point to arrays of strings
 * @s: Point to the string
 * @sz: Size of the array
 *
 * Return: A pointer to a new string
 */
char **splitw(char **sw, char *s, int sz)
{
	int i, j;

	for (i = 0; i < sz; i++)
	{
		j = 0;
		while (*s != ' ' && *s != '\0')
		{
			sw[i][j] = *s;
			s++, j++;
		}
		sw[i][j] = '\0';
		while (*s == ' ')
			s++;
	}
	sw[sz] = NULL;
	return (sw);
}
/**
 * strtow - Splits a string into words
 * @str: Point to the string
 *
 * Return: A pointer to a new string
 *         NULL if it fails
 */
char **strtow(char *str)
{
	int i, j, k;
	char **sw, *s;

	if (*str == '\0' || str == NULL)
		return (NULL);
	while (*str == ' ')
		str++;
	for (i = 0, k = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != ' ' && str[i + 1] == ' ') ||
				(str[i] != ' ' && str[i + 1] == '\0'))
			k += 1;
	}
	if (k == 0)
		return (NULL);
	sw = malloc(sizeof(char *) * (k + 1));
	if (str == NULL)
	{
		free(sw);
		return (NULL);
	}
	s = str;
	for (i = 0; i < k; i++)
	{
		j = 0;
		while (*s != ' ' && *s != '\0')
			s++, j++;
		sw[i] = malloc((j + 1) * sizeof(char));
		if (sw[i] == NULL)
		{
			for (j--; j >= 0; j--)
				free(sw[j]);
			free(sw);
			return (NULL);
		}
		while (*s == ' ')
			s++;
	}
	return (splitw(sw, str, k));
}
