#include "search_algos.h"

/**
 * linear_skip - Searches for an algorithm in a sorted singly
 * @list: A pointer to the  head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 * Description: Prints a value every time it is compared in the list.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *jp;

	if (list == NULL)
		return (NULL);

	for (node = jp = list; jp->next != NULL && jp->n < value;)
	{
		node = jp;
		if (jp->express != NULL)
		{
			jp = jp->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jp->index, jp->n);
		}
		else
		{
			while (jp->next != NULL)
				jp = jp->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jp->index);

	for (; node->index < jp->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
