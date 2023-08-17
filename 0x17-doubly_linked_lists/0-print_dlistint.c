#include "lists.h"
/**
 * print_dlistint - Print all elements in dlistint_t list
 * @h: Head of the dlistint_t list
 * Return: The number of nodes in the list
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t nodes_count = 0;
while (h)
{
nodes_count++;
printf("%d\n", h->n);
h = h->next;
}
return (nodes_count);
}
