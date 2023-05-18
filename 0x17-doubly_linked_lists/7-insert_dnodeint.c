#include <stdlib.h>
#include "lists.h"

/**
 * create_node - creates a new node
 * @n: integer
 *
 * Return: the address of the new node
 *         NULL if it failed
 */
dlistint_t *create_node(int n)
{
	dlistint_t *node = malloc(sizeof(dlistint_t));

	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: the index of the list where the new node should be added
 * @n: integer
 *
 * Return: the address of the new node
 *         NULL if it failed or if it is not possible to add the
 *         new node at index idx
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node_ptr, *tmp;
	unsigned int i = 0;

	if (idx == 0 && !(*h))
	{
		*h = create_node(n);
		return (*h);
	}

	node_ptr = *h;
	while (node_ptr)
	{
		if (idx == 0)
		{
			tmp = create_node(n);
			if (!tmp)
				return (NULL);
			tmp->next = *h;
			*h = tmp;
			return (*h);
		}
		else if (idx == i)
		{
			tmp = create_node(n);
			if (!tmp)
				return (NULL);
			tmp->next = node_ptr;
			tmp->prev = node_ptr->prev;
			(node_ptr->prev)->next = tmp;
			node_ptr->prev = tmp;
			return (tmp);
		}
		node_ptr = node_ptr->next;
		i++;
	}
	return (NULL);
}
