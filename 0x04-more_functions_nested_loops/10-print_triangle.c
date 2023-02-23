#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line
 * @size: The size of the triangle
 *
 * Return: None.
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		i = 1;
		while (i <= size)
		{
			j = size - i;
			while (j > 0)
			{
				_putchar(' ');
				j--;
			}
			k = i;
			while (k > 0)
			{
				_putchar('#');
				k--;
			}
			_putchar('\n');
			i++;
		}
	}
}

