#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	unsigned long int counter_index;
	hash_node_t  *tracker_tmp, *tracker_node;


	for (counter_index = 0; counter_index < ht->size; counter_index++)
	{
		if (ht->array[counter_index] != NULL)
		{
			tracker_node = ht->array[counter_index];
			while (tracker_node != NULL)
			{
				tracker_tmp = tracker_node->next;
				free(tracker_node->key);
				free(tracker_node->value);
				free(tracker_node);
				tracker_node = tracker_tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
