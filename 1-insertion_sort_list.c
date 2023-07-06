#include "sort.h"

/**
 * insertion_sort_list - sorts a doubley linked list of integers
 * in ascending order using insertion algorithm
 * @list: pointer to pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swapNodes(list, current->prev, current);
			print_list(*list);
			continue;
		}
		current = current->next;
	}
}
/**
 * swapNodes - swap two nodes
 * @list: pointer to the head of the list
 * @node1: a node in the doubly linked list
 * @node2: a node in the doubly linked list
 */
void swapNodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *node1_prev, *node2_next;

	if (node1 == NULL || node2 == NULL)
		return;
	node1_prev = node1->prev;
	node2_next = node2->next;

	if (node1_prev != NULL)
		node1_prev->next = node2;
	else
		*list = node2;
	if (node2_next != NULL)
		node2_next->prev = node1;

	node1->prev = node2;
	node1->next = node2_next;
	node2->prev = node1_prev;
	node2->next = node1;
}
