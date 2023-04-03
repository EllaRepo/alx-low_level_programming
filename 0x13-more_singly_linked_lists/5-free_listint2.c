#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _free_listint -  frees a listint_t list
 * @head: pointer to the head of the list
 *
 * Return: None
 */
void _free_listint(listint_t *head)
{
	if (head)
		_free_listint(head->next);
	free(head);
}
/**
 * free_listint2 -  sets the head to NULL
 * @head: pointer to the head of the list
 *
 * Return: None
 */
void free_listint2(listint_t **head)
{
	if (*head)
	{
		_free_listint(*head);
		*head = NULL;
	}
}
