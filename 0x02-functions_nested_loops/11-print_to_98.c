#include "main.h"

void _print_to_98(int n);

/**
 * print_to_98 - Prints all natural number from 'n' to '98',
 *               followed by a new line
 * @n: Input number
 *
 * Return: None.
 */
void print_to_98(int n)
{
	int i;

	if (n > 98)
	{
		_print_to_98(n);
	}
	else
	{
		for (i = n; i < 99; i++)
		{
			int j = i;

			if (i < 0)
			{
				_putchar('-');
				j *= -1;
			}
			if (j > 99)
			{
				_putchar((j / 100) + '0');
				_putchar(((j - 100) / 10) + '0');
				_putchar((j % 10) + '0');
			}
			if (j > 9)
			{
				_putchar((j / 10) + '0');
				_putchar((j % 10) + '0');
			}
			else
			{
				_putchar(j + '0');
			}
			if (i == 98)
				break;
			_putchar(',');
			_putchar(' ');
		}
		_putchar('\n');
	}
}

/**
 * _print_to_98 - Prints all natural number greater than 98,
 *                from 'n' to '98' followed by a new line
 * @n: Input number
 *
 * Return: None.
 */
void _print_to_98(int n)
{
	int i;

	for (i = n; i > 97; i--)
	{
		if (i > 99)
		{
			_putchar((i / 100) + '0');
			_putchar(((i - 100) / 10) + '0');
			_putchar((i % 10) + '0');
		}
		else
		{
			_putchar((i / 10) + '0');
			_putchar((i % 10) + '0');
		}
		if (i == 98)
			break;
		_putchar(',');
		_putchar(' ');
	}
	_putchar('\n');
}
