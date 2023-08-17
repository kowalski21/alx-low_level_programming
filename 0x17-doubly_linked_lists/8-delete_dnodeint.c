/*
 * File: 8-delete_dnodeint.c
 * Auth: Brennan D Baraban
 */

#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node from a dlistint_t
 *                            at a given index.
 * @head: A pointer to the head of the dlistint_t.
 * @index: The index of the node to delete.
 *
 * Return: Upon success - 1.
 *         Otherwise - -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp_list = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (tmp_list == NULL)
			return (-1);
		tmp_list = tmp_list->next;
	}

	if (tmp_list == *head)
	{
		*head = tmp_list->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		tmp_list->prev->next = tmp_list->next;
		if (tmp_list->next != NULL)
			tmp_list->next->prev = tmp_list->prev;
	}

	free(tmp_list);
	return (1);
}
