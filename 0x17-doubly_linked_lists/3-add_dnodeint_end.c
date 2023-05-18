#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: point to the pointer to the head of the list
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node_ptr, *tmp;

	node_ptr = malloc(sizeof(dlistint_t));
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
	node_ptr->prev = tmp;
	tmp->next = node_ptr;
	return (tmp->next);
}
