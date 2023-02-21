#include <stdio.h>

/**
 * main - Computes and prints the sum of all the multiples of
 *        '3' and '5' below '1024', followed by a new line
 *
 * Return: Always 1.
 */
int main(void)
{
	int i, sum;

	for (i = 3; i < 1024; i++)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			sum += i;
	}

	printf("%d \n", sum);
	return (1);
}
