#include <stdio.h>

/**
 * main - Prints all possible different combination of three
 *        digits separated by ',' followed by a space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j, k, l;

	for (i = 48; i < 58; i++)
	{
		for (j = 48; j < 57; j++)
		{
			for (k = i; k < 58; k++)
			{
				for (l = j; l < 58; l++)
				{
					if (i == k && j == l)
						continue;
					putchar (i);
					putchar (j);
					putchar (' ');
					putchar (k);
					putchar (l);
					if (i == 57 && j == 56 && l == 57)
						break;
					putchar (',');
					putchar (' ');
				}
			}
		}
	}
		putchar ('\n');
	return (0);
}
