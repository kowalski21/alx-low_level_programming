#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table.
 * @size: The size of the array.
 * Return: returns pointer to table else error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int count_index;
	hash_table_t *h_tanle;


	h_tanle = malloc(sizeof(hash_table_t));
	if (h_tanle == NULL)
		return (NULL);

	h_tanle->size = size;
	h_tanle->array = malloc(sizeof(hash_node_t *) * size);
	if (h_tanle->array == NULL)
		return (NULL);
	for (count_index = 0; count_index < size; count_index++)
		h_tanle->array[count_index] = NULL;

	return (h_tanle);
}
