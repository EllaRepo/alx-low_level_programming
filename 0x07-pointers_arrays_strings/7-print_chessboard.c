#include "main.h"

/**
 * print_chessboard - Prints the chassboard
 * @a: A pointer to an array of characters
 *
 * Return: None
 */
void print_chessboard(char (*a)[8])
{
	int r, c;

	for (r = 0; r < 8; r++)
	{
		for (c = 0; c < 8; c++)
		{
			if (r > 1 && r < 6)
			{
				_putchar('\n');
				break;
			}
			_putchar(a[r][c]);
		}
		_putchar('\n');
	}
}
