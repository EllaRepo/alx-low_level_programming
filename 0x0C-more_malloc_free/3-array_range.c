#include <stdlib.h>

/**
 * array_range - Creates an array of integers
 * @min: The minimum value of the integer
 * @max: Maximum number of the integer
 *
 * Return: Returns a pointer to an array
 *         NULL if fails
 */
int *array_range(int min, int max)
{
	int *arr, i;

	if (min > max)
		return (NULL);

	arr = malloc(sizeof(int) * (1 + max - min));
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	for (i = 0; (i + min) <= max ; i++)
		arr[i] = i + min;

	return (arr);
}
