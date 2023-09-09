#include "hash_tables.h"

/**
 * hash_table_set - Update or add hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: 1 else 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *bk_ht;
	char *value_copy;
	unsigned long int index, counter_index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (counter_index = index; ht->array[counter_index]; counter_index++)
	{
		if (strcmp(ht->array[counter_index]->key, key) == 0)
		{
			free(ht->array[counter_index]->value);
			ht->array[counter_index]->value = value_copy;
			return (1);
		}
	}

	bk_ht = malloc(sizeof(hash_node_t));
	if (bk_ht == NULL)
	{
		free(value_copy);
		return (0);
	}
	bk_ht->key = strdup(key);
	if (bk_ht->key == NULL)
	{
		free(bk_ht);
		return (0);
	}
	bk_ht->value = value_copy;
	bk_ht->next = ht->array[index];
	ht->array[index] = bk_ht;

	return (1);
}
