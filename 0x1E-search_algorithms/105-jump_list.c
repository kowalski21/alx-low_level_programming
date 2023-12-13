#include "search_algos.h"

/**
 * jump_list - Searches for an algorithm in a sorted singly
 * @list: A pointer to the  head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *
 * Description: Prints a value every time it is compared in the list.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t sp, step_sz;
	listint_t *node, *jp;

	if (list == NULL || size == 0)
		return (NULL);

	sp = 0;
	step_sz = sqrt(size);
	for (node = jp = list; jp->index + 1 < size && jp->n < value;)
	{
		node = jp;
		for (sp += step_sz; jp->index < sp; jp = jp->next)
		{
			if (jp->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jp->index, jp->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jp->index);

	for (; node->index < jp->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
