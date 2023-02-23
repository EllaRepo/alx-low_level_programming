#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers, from 0 to 14,
 *                followed by a new line
 *
 * Return: None.
 */
void more_numbers(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		int j;

		for (j = 0; j < 15; j++)
		{
			if (j > 9)
				_putchar((j / 10) + '0');
			_putchar((j % 10) + '0');
		}
		_putchar('\n');
		i++;
	}
}

