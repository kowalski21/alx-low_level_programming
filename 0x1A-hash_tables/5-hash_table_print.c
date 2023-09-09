#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table to print.
 *
 * Description: Prints out key and value in table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tracker_node;
	unsigned long int counter_index;
	unsigned char my_f = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (counter_index = 0; counter_index < ht->size; counter_index++)
	{
		if (ht->array[counter_index] != NULL)
		{
			if (my_f == 1)
				printf(", ");

			tracker_node = ht->array[counter_index];
			while (tracker_node != NULL)
			{
				printf("'%s': '%s'", tracker_node->key, tracker_node->value);
				tracker_node = tracker_node->next;
				if (tracker_node != NULL)
					printf(", ");
			}
			my_f = 1;
		}
	}
	printf("}\n");
}
