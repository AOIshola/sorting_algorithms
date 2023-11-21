#include "sort.h"

void swap_list_nodes(listint_t **head, listint_t *node_a, listint_t *node_b);
/**
 * insertion_sort_list - sorts a doubly linked list of integers using
 * insertion sort algorithm
 * @list: the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || !*list)
		return;
	current = *list;
	while (current->next)
	{
		if (current->n > current->next->n)
		{
			swap_list_nodes(list, current, current->next);
			print_list(*list);
			current = *list;
		}
		else
			current = current->next;
	}
}
/**
 * swap_list_nodes - swap two nodes of a doubly linked list
 * @head: head of the list
 * @node_a: first node
 * @node_b: second node
 */
void swap_list_nodes(listint_t **head __attribute__((unused)),
		listint_t *node_a, listint_t *node_b)
{
	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	if (node_a->prev)
		node_a->prev->next = node_b;
	else
		*head = node_b;
	node_a->prev = node_b;
	if (node_b->next)
		node_b->next->prev = node_a;
	node_b->next = node_a;
}
