#include "hash_tables.h"

/**
 * shash_table_create - creates sorted  hash table
 * @size: is the size of the array
 *
 * Return: Returns a pointer to the newly created shash table
 *         NULL - If something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table = NULL;
	shash_node_t **sarr = NULL;
	unsigned long int i;

	shash_table = malloc(sizeof(shash_table_t));
	if (!shash_table)
		return (NULL);
	sarr = malloc(sizeof(shash_node_t *) * size);
	if (!sarr)
		return (NULL);
	for (i = 0; i < size; i++)
		sarr[i] = NULL;
	shash_table->size = size;
	shash_table->array = sarr;
	shash_table->shead = NULL;
	shash_table->stail = NULL;
	return (shash_table);
}
/**
 * shash_table_update - updates the sorted hash table
 * @ht: is the sorted hash table you want to add or update the key/value to
 * @new_node: newly added node
 *
 * Return: None
 */
void shash_table_update(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *tmp, *tmp1;

	tmp = tmp1 = ht->shead;
	while (tmp)
	{
		if (strcmp(new_node->key, tmp->key) < 0)
		{
			new_node->sprev = tmp->sprev;
			new_node->snext = tmp;
			if (tmp->sprev)
				tmp->sprev->snext = new_node;
			else
				ht->shead = new_node;
			tmp->sprev = new_node;
			return;
		}
		tmp1 = tmp;
		tmp = tmp->snext;
	}
	new_node->sprev = tmp1;
	new_node->snext = NULL;
	if (ht->shead)
		tmp1->snext = new_node;
	else
		ht->shead = new_node;
	ht->stail = new_node;
}
/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: is the sorted hash table you want to add or update the key/value to
 * @key: is the key
 * @value: is the value associated with the key
 *
 * Return: 1 if it succeeded,
 *         0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(shash_node_t));
	if (!tmp)
		return (0);
	tmp->key = strdup(key);
	tmp->value = strdup(value);
	tmp->next = ht->array[index];
	ht->array[index] = tmp;
	shash_table_update(ht, tmp);

	return (1);
}
/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: is the sorted hash table you want to add or update the key/value to
 * @key: is the key
 *
 * Return: the value associated with the element
 *         NULL -  if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}
/**
 * shash_table_print - prints a sorted hash table.
 * @ht: is the hash table
 *
 * Return: None
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char *sepa;

	if (ht == NULL)
		return;
	sepa = "";
	printf("{");
	for (tmp = ht->shead; tmp != NULL; tmp = tmp->snext)
	{
		printf("%s\'%s\': \'%s\'", sepa, tmp->key, tmp->value);
		sepa = ", ";
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * order using the sorted linked list
 * @ht: is the hash table
 *
 * Return: None
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char *sepa;

	if (ht == NULL)
		return;
	sepa = "";
	printf("{");
	for (tmp = ht->stail; tmp != NULL; tmp = tmp->sprev)
	{
		printf("%s\'%s\': \'%s\'", sepa, tmp->key, tmp->value);
		sepa = ", ";
	}
	printf("}\n");
}
/**
 * shash_table_delete - deletes a hash table
 * @ht: is the hash table
 *
 * Return: None
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp, *tmp1;
	unsigned long int index;

	if (ht == NULL)
		return;
	for (index = 0; index < ht->size; index++)
	{
		tmp = ht->array[index];
		while (tmp)
		{
			tmp1 = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = tmp1;
		}
	}
	free(ht->array);
	free(ht);
}
