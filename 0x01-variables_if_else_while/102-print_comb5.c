#include <stdio.h>

/**
 * main - Prints all possible different combination of two
 *        two-digits numbers separated by ',' followed by a space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int k, l;
	
	for (k = 0; k < 99; k++)
	{
		for (l = k + 1; l <= 99; l++)
		{
			putchar ((k / 10) + '0');
			putchar ((k % 10) + '0');
			putchar (' ');
			putchar ((l / 10) + '0');
			putchar ((l % 10) + '0');
 			if (k == 98 && l == 99)
				break;
			putchar (',');
			putchar (' ');
		}
	}
	putchar ('\n');
	return (0);
}
