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

	tmp = create_node(n);
	if (!tmp)
		return (NULL);
	if (idx == 0 && !(*h))
	{
		*h = tmp;
		return (*h);
	}

	node_ptr = *h;
	while (node_ptr)
	{
		if (idx == 0)
		{
			tmp->next = *h;
			*h = tmp;
			return (*h);
		}
		else if (idx == i + 1)
		{
			tmp->next = node_ptr->next;
			tmp->prev = node_ptr;
			if (node_ptr->next)
				(node_ptr->next)->prev = tmp;
			node_ptr->next = tmp;
			return (tmp);
		}
		node_ptr = node_ptr->next;
		i++;
	}
	free(tmp);
	return (NULL);
}
