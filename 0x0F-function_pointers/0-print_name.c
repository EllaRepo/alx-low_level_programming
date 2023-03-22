#include <stddef.h>

/**
 * print_name - Prints a name
 * @name: name string
 * @f: function pointer
 *
 * Return: None
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
