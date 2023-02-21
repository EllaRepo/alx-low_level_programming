#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers,
 *        starting with '1' and '2', followed by a new line
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	long int previous, current;

	previous = 1;
	current = 2;
	printf("%ld, %ld, ", previous, current);

	for (i = 0; i < 48; i++)
	{
		long int tmp;

		tmp = previous + current;
		printf("%ld", tmp);
		if (i == 47)
			break;
		printf(", ");
		previous = current;
		current = tmp;
	}
	printf("\n");
	return (0);
}
