#include "sort.h"

/**
 * swap - Swaps nodes of doubly linked list.
 *
 * @node2: Node to end up on right.
 * @node1: Node to end up on left.
 */

void swap(listint_t *node2, listint_t *node1)
{
	listint_t *temp, *right = node2, *left = node1;

	temp = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;
	right->prev = temp;
	if (left->next)
		left->next->prev = left;
	if (right->prev)
		right->prev->next = right;
}

/**
 * insertion_sort_list - Sorts doubly linked list of integers
 * in ascending order using insertion sort algorithm.
 *
 * @list: List to sort.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nav, *current;

	if (list == NULL || *list == NULL)
		return;

	nav = (*list)->next;

	while (nav)
	{
		current = nav;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap(current, current->prev);
				while ((*list)->prev)
					*list = (*list)->prev;
				print_list(*list);
				continue;
			}
			current = current->prev;
		}
		nav = nav->next;
	}
}
