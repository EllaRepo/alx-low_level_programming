#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a list_t list
 * @head: point to the pointer to the head of the list
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node_ptr = malloc(sizeof(listint_t));

	if (!node_ptr)
		return (NULL);
	node_ptr->next = *head;
	node_ptr->n = n;
	*head = node_ptr;

	return (*head);
}
