#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swaps node in a listint_t doubly-linked list
 *                   list of ints with the node ahead of it.
 * @list: Pointer to the head of a doubly-linked list of integers.
 * @tail: Pointer to the tail of the doubly-linked list.
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_node_behind - Swaps node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: Pointer to the head of a doubly-linked list of ints.
 * @tail: Pointer to the tail of the doubly-linked list.
 * @shaker: Pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shkr)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shkr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shkr)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Sorts listint_t doubly-linked list of ints in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: Pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shkr;
	bool sns = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (sns == false)
	{
		sns = true;
		for (shkr = *list; shkr != tail; shkr = shkr->next)
		{
			if (shkr->n > shkr->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				sns = false;
			}
		}
		for (shkr = shakr->prev; shkr != *list;
				shaker = shaker->prev)
		{
			if (shkr->n < shkr->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				sns = false;
			}
		}
	}
}
