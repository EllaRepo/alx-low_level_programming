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
	for (; j >= 1; j /= 10)
	{
		_putchar(((i / j) % 10) + '0');
	}
}

