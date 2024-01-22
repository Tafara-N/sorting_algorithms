#include "sort.h"

void swapping_node_ahead(listint_t **list, listint_t **tail,
							listint_t **shaker);
void swapping_node_behind(listint_t **list, listint_t **tail,
							listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swapping_node_ahead - Swapping a node in a listint_t doubly linked list
 *                   list of integers with the node ahead of it
 * @list: Pointer to the head of a doubly linked list of integers
 * @tail: Pointer to the tail of the doubly linked list
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo
 */

void swapping_node_ahead(listint_t **list, listint_t **tail,
							listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swapping_node_behind - Swapping a node in a listint_t doubly linked
 *                    list of integers with the node behind it
 * @list: Pointer to the head of a doubly linked list of integers
 * @tail: Pointer to the tail of the doubly linked list
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo
 */

void swapping_node_behind(listint_t **list, listint_t **tail,
							listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Sorting a listint_t doubly linked list of integers in
 *                      ascending order using the cocktail shaker algorithm
 * @list: Pointer to the head of a listint_t doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	Boolean shaken_not_stirred = False;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == False)
	{
		shaken_not_stirred = True;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swapping_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = False;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swapping_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = False;
			}
		}
	}
}
