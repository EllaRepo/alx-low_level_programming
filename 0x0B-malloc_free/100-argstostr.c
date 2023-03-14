#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: The number of argument
 * @av: Point to the arguments
 *
 * Return: A pointer to a new string
 *         NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, j, k;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	k = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			k += 1;
			j++;
		}
	}
	str = malloc(sizeof(char) * (k + ac + 1));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	for (i = 0, k = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			str[k] = av[i][j];
			j++, k++;
		}
		if (av[i][j] == '\0')
		{
			str[k] = '\n';
			k++;
		}
	}
	str[k] = '\0';
	return (str);
}
