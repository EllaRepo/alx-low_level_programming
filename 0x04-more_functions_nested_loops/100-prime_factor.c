#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of the number 612852475143,
 * followed by a new line.
 *
 * Return: Always 0
 */
int main(void)
{
	long int i, n, largest_pn;

	n = 612852475143;
	i = 3;
	while (i <= n)
	{
		if (n % i == 0)
		{
			if (i > largest_pn)
				largest_pn = i;
			n = n / i;
			i = 1;
		}
		i += 2;
	}
	printf("%ld\n", largest_pn);
	return (0);
}

