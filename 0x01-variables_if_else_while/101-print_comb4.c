#include <stdio.h>

/**
 * main - Prints all possible different combination of three
 *        digits separated by ',' followed by a space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 48;
	int j, k;

	while (i < 56)
	{
		for (j = i + 1; j < 57; j++)
		{
			for (k = j + 1; k < 58; k++)
			{
				putchar (i);
				putchar (j);
				putchar (k);
				if (i == 55)
					break;
				putchar (',');
				putchar (' ');
			}
		}
		i++;
	}
		putchar ('\n');
	return (0);
}
