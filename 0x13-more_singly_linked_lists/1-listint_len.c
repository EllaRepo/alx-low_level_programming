#include <stddef.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: pointer to list_t
 *
 * Return: Number of nodes
 */
size_t listint_len(const listint_t *h)
{
	if (!h)
		return (0);
	return (1 + listint_len((const listint_t *) h->next));
}
