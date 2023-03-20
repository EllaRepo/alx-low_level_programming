#include <stdlib.h>
#include "dog.h"

/**
 * _memcpy - Copies memory area
 * @dest: Point to memory area of destination
 * @src: Point to memory area of source
 * @n: Number of bytes of a memory area
 *
 * Return: Returns a pointer to 'dest'
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
/**
  * _strlen - returns the length of a string
  * @str:  the string
  *
  * Return: the length of a string
  */
int _strlen(char *str)
{
	char *s;

	for (s = str; *s; s++)
		;
	return (s - str);
}
/**
  * _strdup - Duplicates a string
  * @str: point to a string
  *
  * Return: a pointer to the new string
  */
char *_strdup(char *str)
{
	int len;
	char *copy;

	len = _strlen(str) + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	_memcpy(copy, str, len);
	return (copy);
}
/**
 * new_dog - Creates a new dog
 * @name: name of a dog
 * @age: age of a dog
 * @owner: owner of a dog
 *
 * Return: a pointer to the new created dog struct
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *nd = malloc(sizeof(dog_t));

	if (nd == NULL)
		return (NULL);

	nd->name = _strdup(name);
	if (nd->name == NULL)
	{
		free(nd);
		return (NULL);
	}
	nd->owner = _strdup(owner);
	if (nd->owner == NULL)
	{
		free(nd->name);
		free(nd);
		return (NULL);
	}
	nd->age = age;

	return (nd);
}
