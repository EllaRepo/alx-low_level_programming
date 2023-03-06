#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix
 *                  of integers
 * @a: A pointer to an integer
 * @size: The size of the matrix
 *
 * Return: None
 */
void print_diagsums(int *a, int size)
{
	int princ, secon, r, c;

	if (size <= 0)
		return;

	princ = 0;
	secon = 0;

	for (r = 0; r < size; r++)
	{
		for (c = 0; c < 8; c++)
		{
			if (r == c)
				princ += *(a + (r * size + c));
			if ((r + c) == (size - 1))
				secon += *(a + (r * size + c));
		}
	}
	printf("%d, %d\n", princ, secon);
}
