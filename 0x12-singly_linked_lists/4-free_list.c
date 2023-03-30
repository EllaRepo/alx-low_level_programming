#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _free -  frees a list_t list except the head
 * @head: pointer to the head of the list
 *
 * Return: None
 */
void _free(list_t *head)
{
	if (head->next)
		_free(head->next);
	free(head->str);
	free(head->next);
}
/**
 * free_list -  frees a list_t list
 * @head: pointer to the head of the list
 *
 * Return: None
 */
void free_list(list_t *head)
{
	if (!head)
		return;
	_free(head);
	free(head);
}
