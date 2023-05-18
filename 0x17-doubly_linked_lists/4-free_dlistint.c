#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint -  frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: None
 */
void free_dlistint(dlistint_t *head)
{
	if (head)
		free_dlistint(head->next);
	free(head);
}
