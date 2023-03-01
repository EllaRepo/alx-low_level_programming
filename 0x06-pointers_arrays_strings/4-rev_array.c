/**
 * reverse_array - Reverses the content of an array of integers
 * @a: A pointer to an integer array
 * @n: The number of elements of the array
 *
 * Return: None.
 */
void reverse_array(int *a, int n)
{
	int i, tmp, *num;

	num = a;
	i = 0;
	while (i < n / 2)
	{
		tmp = num[n - i - 1];
		num[n - i - 1] = num[i];
		num[i] = tmp;
		i++;
	}
}

