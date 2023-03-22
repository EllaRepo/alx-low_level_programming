/**
 * print_name - Prints a name
 * @name: name string
 * @fe: function pointer
 *
 * Return: None
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
