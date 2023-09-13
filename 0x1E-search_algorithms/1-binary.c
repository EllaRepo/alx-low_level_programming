#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers using
 * the Binary search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: first index where value is located
 *         -1 If value is not present in array or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l, r, m;

	if (array != NULL && size > 0)
	{
		l = 0;
		r = size - 1;
		while (l <= r)
		{
			printf("Searching in array: %d", array[l]);
			for (m = l + 1; m <= r; m++)
				printf(", %d", array[m]);
			printf("\n");
			m = (l + r) / 2;
			if (array[m] < value)
				l = m + 1;
			else if (array[m] > value)
				r = m - 1;
			else
				return (m);
		}
	}
	return (-1);
}
