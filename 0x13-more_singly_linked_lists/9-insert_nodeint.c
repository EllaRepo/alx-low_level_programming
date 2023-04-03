#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index -  inserts a new node at a given position
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

	if (*head == NULL && idx != 0)
		return (NULL);
	tmp = malloc(sizeof(listint_t));
	if (!tmp)
		return (NULL);
	tmp->n = n;
	if (idx == 0)
	{
		if (head)
		{
			tmp->next = *head;
			*head = tmp;
		}
		else
		{
			tmp->next = NULL;
			*head = tmp;
		}
		return (*head);
	}
	node_ptr = *head;
	while (node_ptr)
	{
		if (idx == i + 1)
		{
			tmp->next = node_ptr->next;
			node_ptr->next = tmp;
			return (node_ptr->next);
		}
		node_ptr = node_ptr->next;
		i++;
	}
	free(tmp);
	return (NULL);
}
