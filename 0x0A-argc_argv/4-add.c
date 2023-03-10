#include <stdio.h>
#include <stdlib.h>

/**
 * main - Adds positive numbers and prints the result
 * @argc: The number of command line arguments
 * @argv: An array of pointers pointing to the arguments
 *
 * Return: 0 if all arguments are valid
 *         1 otherwise
 */
int main(int argc, char *argv[])
{
	char *s;
	int sum, tmp;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (sum = 0, tmp = 0, argv++; *argv != NULL; argv++)
	{
		s = *argv;
		if (*s == '-')
			++s;
		while (*s != '\0')
		{
			if (*s < '0' || *s > '9')
			{
				printf("Error\n");
				return (1);
			}
			s++;
		}
		tmp = atoi(*argv);
		sum += tmp > 0 ? tmp : 0;
	}
	printf("%d\n", sum);

	return (0);
}
