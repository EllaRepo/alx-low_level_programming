#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: point to the pointer to the head of the list
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node_ptr, *tmp;

	node_ptr = malloc(sizeof(listint_t));
	if (!node_ptr)
		return (NULL);
	node_ptr->next = NULL;
	node_ptr->n = n;

	if (!(*head))
	{
		*head = node_ptr;
		return (*head);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node_ptr;
	return (tmp->next);
}
