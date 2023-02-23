#include "main.h"

/**
 * print_number - Prints an integer using '_putchar' function
 * @n: The integer to be printed
 *
 * Return: None.
 */
void print_number(int n)
{
	unsigned int i, j;


	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	i = n;
	j = 1;
	while (i / 10)
	{
		j *= 10;
		i /= 10;
	}
	i = n;
	while (j > 1)
	{
		_putchar((i / j) + '0');
		i = i - ((i / j) * j);
		j /= 10;
	}
	_putchar((n % 10) + '0');
}

