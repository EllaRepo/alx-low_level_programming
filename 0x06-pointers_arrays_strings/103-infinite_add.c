void reverse_array(char *a, int n);

/**
 * infinite_add - Adds two numbers
 * @n1: A char pointer to the first number
 * @n2: A char pointer to the second number
 * @r: A char pointer to the buffer
 * @size_r: The buffer size
 *
 * Return: A pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	char *num1, *num2, *buff;
	int i, j, k, rem, sum;

	num1 = n1;
	num2 = n2;
	buff = r;
	for (i = 0; *num1 != '\0'; num1++)
		i++;
	for (j = 0; *num2 != '\0'; num2++)
		j++;
	if (size_r < i + 1 || size_r < j + 1)
		return (0);
	num1 = n1, num2 = n2;
	rem = 0;
	sum = 0;
	i -= 1;
	j -= 1;
	for (k = 0; i >= 0 && j >= 0; i--, j--, k++)
	{
		sum = num1[i] + num2[j] + rem - 96;
		buff[k] = (sum % 10) + '0';
		rem = sum / 10;
	}
	for (; i >= 0 && k < size_r; i--, k++)
	{
		sum = num1[i] + rem - 48;
		buff[k] = (sum % 10) + '0';
		rem = sum / 10;
	}
	for (; j >= 0 && k < size_r; j--, k++)
	{
		sum = num2[j] + rem - 48;
		buff[k] = (sum % 10) + '0';
		rem = sum / 10;
	}
	if (rem && k == size_r - 1)
		return (0);
	if (rem && k < size_r)
	{
		buff[k] = rem + '0';
		buff[k + 1] = '\0';
	}
	else
	{
		buff[k] = '\0';
	}
	i = rem ? k + 1 : k;
	reverse_array(r, i);
	return (r);
}
/**
 * reverse_array - Reverses the content of an array of integers
 * @a: A pointer to an integer array
 * @n: The number of elements of the array
 *
 * Return: None.
 */
void reverse_array(char *a, int n)
{
	int i;
	char *num, tmp;

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
