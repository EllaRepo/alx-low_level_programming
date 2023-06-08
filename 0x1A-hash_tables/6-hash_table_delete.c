#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: is the hash table
 *
 * Return: None
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp, *tmp1;
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
