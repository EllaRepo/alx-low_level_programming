#include <stdlib.h>

/**
 * alloc_grid - Returns a pointer to a 2 dimensional array of integers
 * @width: Width of the array
 * @height: Height of the array
 *
 * Return: Returns a pointer to a 2-d array of integers
 *         NULL if s1=s2=NULL or insufficient memory was available
 */
int **alloc_grid(int width, int height)
{
	int **arr, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	arr = (int **)malloc(sizeof(int *) * height);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		arr[i]  = (int *)malloc(sizeof(int) * width);
		if (arr[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(arr[j]);
				j++;
			}
			free(arr);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			arr[i][j] = 0;
	}
	return (arr);
}
