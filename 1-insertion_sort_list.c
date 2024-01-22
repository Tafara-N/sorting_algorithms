#include "sort.h"

/**
 * swapping_nodes - Swapping two nodes in a listint_t doubly linked list
 * @h: Pointer to the head of the doubly-linked list.
 * @n1: Pointer to the first node to swap
 * @n2: Second node to swap
 */

void swapping_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorting a doubly linked list of integers
 *                       using Insertion Sort Algorithm
 * @list: Pointer to the head of a doubly linked list of integers
 *
 * Description: Printing the list after every swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *again, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (again = (*list)->next; again != NULL; again = temp)
	{
		temp = again->next;
		insert = again->prev;

		while (insert != NULL && again->n < insert->n)
		{
			swapping_nodes(list, &insert, again);
			print_list((const listint_t *)*list);
		}
	}
}
