#include <stdlib.h>
#include <stdio.h>
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
		printf("*arr\n");
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		arr[i]  = (int *)malloc(sizeof(int) * width);
		if (arr[i] == NULL)
			return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			arr[i][j] = 0;
	}
	return (arr);
}
