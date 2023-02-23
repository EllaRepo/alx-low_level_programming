#include "main.h"

/**
 * print_diagonal - Draws a diagonal line on the terminal
 * @n: The  number of times the character '\' should be printed
 *
 * Return: None.
 */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		i = 1;
		while (i <= n)
		{
			j = i - 1;
			while (j > 0)
			{
				_putchar(' ');
				j--;
			}
			_putchar('\\');
			_putchar('\n');
			i++;
		}
	}
}

