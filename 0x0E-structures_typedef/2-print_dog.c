#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints a 'struct dog'
 * @d: the structure to be printed
 *
 * Return: None
 */
void print_dog(struct dog *d)
{
	char *s;

	if (d == NULL)
		return;
	s = d->name == NULL ? "(nil)" : d->name;
	printf("Name: %s\n", s);
	printf("Age: %f\n", d->age);
	s = d->owner == NULL ? "(nil)" : d->owner;
	printf("Owner: %s\n", s);
}
