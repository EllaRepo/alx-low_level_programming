#include <stdlib.h>
#include "lists.h"

/**
 * create_node - creates a new node
 * @n: integer
 *
 * Return: the address of the new node
 *         NULL if it failed
 */
listint_t *create_node(int n)
{
	listint_t *node = malloc(sizeof(listint_t));

	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}
/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head of the list
 * @idx: the index of the list where the new node should be added
 * @n: integer
 *
 * Return: the address of the new node
 *         NULL if it failed or if it is not possible to add the
 *         new node at index idx
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node_ptr, *tmp;
	unsigned int i = 0;

	if (idx == 0 && !(*head))
	{
		*head = create_node(n);
		return (*head);
	}

	node_ptr = *head;
	while (node_ptr)
	{
		if (idx == 0)
		{
			tmp = create_node(n);
			if (!tmp)
				return (NULL);
			tmp->next = *head;
			*head = tmp;
			return (*head);
		}
		else if (idx - 1 == i)
		{
			tmp = create_node(n);
			if (!tmp)
				return (NULL);
			tmp->next = node_ptr->next;
			node_ptr->next = tmp;
			return (tmp);
		}
		node_ptr = node_ptr->next;
		i++;
	}
	return (NULL);
}
