/**
 * sqrt_recursion - Returns the natural square root of a number
 * @n: The number
 * @sqrt: Square root of the intermidiary number
 * @tmp: Temporary valu
 *
 * Return: Natural square root
 *         -1 if the number doesn't have natural square root
 */
int sqrt_recursion(int n, int sqrt, int tmp)
{
	if (n == 1)
		return (1);
	if (n < 0)
		return (-1);
	if (sqrt == tmp)
	{
		if (sqrt * tmp == n)
			return (sqrt);
		else
			return (-1);
	}
	tmp = sqrt;

	return (sqrt_recursion(n, ((n / tmp) + tmp) / 2, tmp));
}
/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number
 *
 * Return: Natural square root
 *         -1 if the number doesn't have natural square root
 */
int _sqrt_recursion(int n)
{
	return (sqrt_recursion(n, n / 2, 0));
}
