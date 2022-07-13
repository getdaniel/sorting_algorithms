#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly LL of integers in ascending order.
 *
 * @list: The list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (index = (*list)->next; index != NULL; index = tmp)
	{
		tmp = index->next;
		insert = index->prev;

		while (insert != NULL && index->n < insert->n)
		{
			swap_nodes(list, &insert, index);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - Swap two nodes.
 *
 * @list: A pointer to the head of the list.
 * @insert: A pointer to the first node to swap.
 * @index: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t **insert, listint_t *index)
{
	(*insert)->next = index->next;
	if (index->next != NULL)
		index->next->prev = *insert;
	index->prev = (*insert)->prev;
	index->next = *insert;
	if ((*insert)->prev != NULL)
		(*insert)->prev->next = index;
	else
		*list = index;
	(*insert)->prev = index;
	*insert = index->prev;
}
