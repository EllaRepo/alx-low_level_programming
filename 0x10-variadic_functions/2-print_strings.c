#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: the string to be printed between numbers
 * @n: the number of integers passed to the function
 *
 * Return: None
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;
	char *cp;

	if (n == 0)
	{
		;
	}
	else
	{
		va_start(ap, n);
		for (i = 0; i < n; i++)
		{
			cp = va_arg(ap, char *);
			cp = cp ? cp : "(nil)";
			printf("%s", cp);
			if (separator && (i < n - 1))
				printf("%s", separator);
		}
		va_end(ap);
	}
	printf("\n");
}
