#include "main.h"

void _print_two_digits(int n);
void _print_three_digits(int n);

/**
 * print_times_table - Prints the 'n' times table, starting with 0
 * @n: Input number for time table
 *
 * Return: None
 */
void print_times_table(int n)
{
	int i, j, res;

	if (n > 15 || n < 0)
		return;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			res = i * j;
			if (res < 10)
			{
				_putchar(res + '0');
			}
			else if (res < 100)
			{
				_print_two_digits(res);
			}
			else
			{
				_print_three_digits(res);
			}
			if (j == n)
				break;
			_putchar(',');
			_putchar(' ');
			if ((i * (j + 1)) < 10)
			{
				_putchar(' ');
				_putchar(' ');
			}
			else if ((i * (j + 1)) < 100)
			{
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}

/**
 * _print_two_digits - Prints two digits number
 * @n: Input number to be printed
 *
 * Return: None
 */
void _print_two_digits(int n)
{
	_putchar((n / 10) + '0');
	_putchar((n % 10) + '0');
}


/**
 * _print_three_digits - Prints three digit number
 * @n: Input number to be printed
 *
 * Return: None
 */
void _print_three_digits(int n)
{
	_putchar((n / 100) + '0');
	_putchar(((n - 100) / 10) + '0');
	_putchar((n % 10) + '0');
}
