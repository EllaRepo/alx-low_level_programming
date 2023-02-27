#include <stdio.h>

/**
 * print_array - Prints 'n' elements of an array of integers,
 * followed by a new line.
 * @a: A pointer to an int array
 * @n: The number of elements to be printed
 *
 * Return: None.
 */
void print_array(int *a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%d", a[i++]);
		if (i == n)
			break;
		printf(", ");
	}
	printf("\n");
}

