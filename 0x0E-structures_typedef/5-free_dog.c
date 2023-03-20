#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees dogs
 * @d: point to the structure to be freed
 *
 * Return: None
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;
	free(d->name);
	free(d->owner);
	free(d);
}
