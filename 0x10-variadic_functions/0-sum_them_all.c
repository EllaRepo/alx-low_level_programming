#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all of its parameters
 * @n: number of parameters
 *
 * Return: sum of parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int i;
	va_list ap;

	if (n == 0)
		return (0);

	va_start(ap, n);
	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);
	va_end(ap);

	return (sum);
}
