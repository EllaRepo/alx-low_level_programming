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
	int sum;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (sum = 0, argv++; *argv != NULL; argv++)
	{
		if (atoi(*argv) > 0)
		{
			sum += atoi(*argv);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);

	return (0);
}
