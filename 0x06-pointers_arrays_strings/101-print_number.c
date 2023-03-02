#include "main.h"

/**
 * print_number - Prints an integer
 * @n: An integer to be printed
 *
 * Return: None.
 */
void print_number(int n)
{
	unsigned int i, j;

	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}
	for (i = n, j = 1; i / 10 > 0; j *= 10, i /= 10)
		;
	for (i = n; j >= 1; j /= 10)
		_putchar(((i / j) % 10) + '0');
}
