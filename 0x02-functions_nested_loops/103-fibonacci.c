#include <stdio.h>

/**
 * main - Prints the sum of the even valued terms of Fibonacci sequence,
 *        whose values don't exceed 4 million starting with '1' and '2',
 *        followed by a new line
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	long int previous, current, sum;

	previous = 1;
	current = 2;
	sum = 2;
	for (i = 0; i <= 4000000;)
	{
		long int tmp;

		tmp = previous + current;
		if (tmp > 4000000)
			break;
		previous = current;
		current = tmp;
		if (tmp % 2 == 0)
			sum += tmp;
		i = tmp;
	}
	printf("%ld\n", sum);
	return (0);
}
