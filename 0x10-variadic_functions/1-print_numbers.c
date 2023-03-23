#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - prints a number followed by a new line
 * @separator: the string to be printed between numbers
 * @n: the number of integers passed to the function
 *
 * Return: None
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	if (n == 0)
	{
		;
	}
	else
	{
		va_start(ap, n);
		for (i = 0; i < n; i++)
		{
			printf("%d", va_arg(ap, int));
			if (separator != NULL && (i < n - 1))
				printf("%s", separator);
		}
		va_end(ap);
	}
	printf("\n");
}
