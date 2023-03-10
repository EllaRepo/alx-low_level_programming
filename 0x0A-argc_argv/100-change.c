#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins to make change for
 *        an amount of money
 * @argc: The number of command line arguments
 * @argv: An array of pointers pointing to the arguments
 *
 * Return: 0 if all arguments are valid
 *         1 if the number of arguments if different from 1
 */
int main(int argc, char *argv[])
{
	int cents, count;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents <= 0)
	{
		cents = 0;
	}
	else
	{
		count = 0;
		while (cents)
		{
			if (cents >= 25)
				cents -= 25, count += 1;
			else if (cents >= 10)
				cents -= 10, count += 1;
			else if (cents >= 5)
				cents -= 5, count += 1;
			else if (cents >= 2)
				cents -= 2, count += 1;
			else
				cents -= 1, count += 1;
		}
	}
	printf("%d\n", count);
	return (0);
}
