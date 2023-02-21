#include "main.h"

/**
 * times_table - Prints the 9 time table, starting with 0,
 *
 * Return: None
 */
void times_table(void)
{
	int i, j, res;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			res = i * j;
			if (res < 10)
			{
				_putchar(res + '0');
			}
			else
			{
				_putchar((res / 10) + '0');
				_putchar((res % 10) + '0');
			}
			if (j == 9)
				break;
			_putchar(',');
			_putchar(' ');
			if ((i * (j + 1)) < 10)
				_putchar(' ');

		}
		_putchar('\n');
	}
}


