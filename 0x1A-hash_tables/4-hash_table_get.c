#include "hash_tables.h"

/**
 * hash_table_get - Get the value based on key
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 * Return: null if key cannot be matched
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *track_node;
	unsigned long int index_key;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index_key = key_index((const unsigned char *)key, ht->size);
	if (index_key >= ht->size)
		return (NULL);

	track_node = ht->array[index_key];
	while (track_node && strcmp(track_node->key, key) != 0)
		track_node = track_node->next;

	return ((track_node == NULL) ? NULL : track_node->value);
}
