#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of tracker_node sorted hash table.
 *
 * Return: null else value
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *_ht;
	unsigned long int i;

	_ht = malloc(sizeof(shash_table_t));
	if (_ht == NULL)
		return (NULL);

	_ht->size = size;
	_ht->array = malloc(sizeof(shash_node_t *) * size);
	if (_ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		_ht->array[i] = NULL;
	_ht->shead = NULL;
	_ht->stail = NULL;

	return (_ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key.
 * @value: Returned value.
 *
 * Return: 1 else 0 if it fails
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *tracker_node, *tracker_tmp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tracker_tmp = ht->shead;
	while (tracker_tmp)
	{
		if (strcmp(tracker_tmp->key, key) == 0)
		{
			free(tracker_tmp->value);
			tracker_tmp->value = value_copy;
			return (1);
		}
		tracker_tmp = tracker_tmp->snext;
	}

	tracker_node = malloc(sizeof(shash_node_t));
	if (tracker_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	tracker_node->key = strdup(key);
	if (tracker_node->key == NULL)
	{
		free(value_copy);
		free(tracker_node);
		return (0);
	}
	tracker_node->value = value_copy;
	tracker_node->next = ht->array[index];
	ht->array[index] = tracker_node;

	if (ht->shead == NULL)
	{
		tracker_node->sprev = NULL;
		tracker_node->snext = NULL;
		ht->shead = tracker_node;
		ht->stail = tracker_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		tracker_node->sprev = NULL;
		tracker_node->snext = ht->shead;
		ht->shead->sprev = tracker_node;
		ht->shead = tracker_node;
	}
	else
	{
		tracker_tmp = ht->shead;
while (tracker_tmp->snext != NULL && strcmp(tracker_tmp->snext->key, key) < 0)
tracker_tmp = tracker_tmp->snext;
		tracker_node->sprev = tracker_tmp;
		tracker_node->snext = tracker_tmp->snext;
		if (tracker_tmp->snext == NULL)
			ht->stail = tracker_node;
		else
			tracker_tmp->snext->sprev = tracker_node;
		tracker_tmp->snext = tracker_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value by value
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: get value else null
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Printf a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tracker_tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		tracker_tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tracker_tmp;
	}

	free(head->array);
	free(head);
}
