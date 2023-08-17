#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node in a dlistint_t
 * @h: A pointer to the head of the dlistint_t list.
 * @idx: The position to insert the new node.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp_list = *h, *new_list;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		tmp_list = tmp_list->next;
		if (tmp_list == NULL)
			return (NULL);
	}

	if (tmp_list->next == NULL)
		return (add_dnodeint_end(h, n));

	new_list = malloc(sizeof(dlistint_t));
	if (new_list == NULL)
		return (NULL);

	new_list->n = n;
	new_list->prev = tmp_list;
	new_list->next = tmp_list->next;
	tmp_list->next->prev = new_list;
	tmp_list->next = new_list;

	return (new_list);
}
