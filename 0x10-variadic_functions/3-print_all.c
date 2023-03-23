#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: a list of types of arguments passed to the function
 *
 * Return: None
 */
void print_all(const char * const format, ...)
{
	int isvalid, i;
	char *s;
	va_list ap;

	if (format != NULL || *format != '\0')
	{
		va_start(ap, format);
		s = NULL, i = 0;
		while (format[i])
		{
			isvalid = 1;
			switch (format[i])
			{
				case 'c':
					printf("%c", va_arg(ap, int));
					break;
				case 'i':
					printf("%d", va_arg(ap, int));
					break;
				case 'f':
					printf("%f", va_arg(ap, double));
					break;
				case 's':
					s = va_arg(ap, char *);
					s = s ? s : "(nil)";
					printf("%s", s);
					break;
				default:
					isvalid = 0;
					break;
			}
			if (isvalid && format[i + 1] != '\0')
				printf(", ");
			i++;
		}
		va_end(ap);
	}
	printf("\n");
}
