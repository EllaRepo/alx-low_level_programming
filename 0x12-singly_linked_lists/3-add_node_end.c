#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * _strlen - Returnns the length of a string
 * @s: Pointer to a characher
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}
/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: point to the pointer to the head of the list
 * @str: string to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node_ptr;
	const char *s = str;

	node_ptr = *head;
	while(node_ptr)
	{
		if(!node_ptr->next)
		{
			node_ptr->next = malloc(sizeof(list_t));
			if (!node_ptr->next)
				return (NULL);
			node_ptr->next->str = strdup(str);
			node_ptr->next->len = _strlen(s);
			node_ptr->next->next = NULL;
			return (node_ptr->next);
		}
		node_ptr = node_ptr->next;
	}	
	node_ptr = malloc(sizeof(list_t));
	if (!node_ptr)
		return (NULL);
	node_ptr->next = NULL;
	node_ptr->str = strdup(str);
	node_ptr->len = _strlen(s);
	*head = node_ptr;

	return (*head);
}
