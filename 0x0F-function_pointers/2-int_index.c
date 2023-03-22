#include <stddef.h>

/**
 * int_index - serches for an integer
 * @array: array of int
 * @size: size of the array
 * @cmp: function pointer
 *
 * Return: the index of the first element for which the cmp
 *         function does not return 0
 *         0 if no element matches
 *        -1 if size is less than or equal to
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size < 1 || array == NULL || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
		if (cmp(array[i]) != 0)
			return (i);
	return (-1);
}
