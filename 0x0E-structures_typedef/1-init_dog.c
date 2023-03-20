#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - Initializes a variable of type 'struct dog'
 * @d: the structure to be initialized
 * @name: point to the 'name' member value
 * @age: value for the 'age' member value
 * @owner: point to the 'owner' member value
 *
 * Return: None
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
