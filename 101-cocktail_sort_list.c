#include "sort.h"
void swap_nodes(listint_t **list, listint_t *node);
void swapNodes(listint_t *l, listint_t *r, listint_t **h)
{
	listint_t *temp;

	temp = l->prev;
	if (temp)
		temp->next = r;
	r->prev = temp;
	l->prev = r;
	l->next = r->next;
	r->next = l;
	if (l->next != NULL)
		l->next->prev = l;
	if (r->prev == NULL)
		*h = r;
	print_list(*h);
}

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = *list;
	listint_t *tail;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current != NULL)
		{
			if (current->next)
			{
				if (current->n > current->next->n)
				{
					swapNodes(current, current->next, list);
					swapped = 1;
				}
			}

			if (current->next == NULL)
				tail = current;
			current = current->next;
		}

		if (!swapped)
			break;

		while (tail->prev != NULL)
		{
			if (tail->prev->n > tail->n)
			{
				swapNodes(tail->prev, tail, list);
				swapped = 1;
			}
			tail = tail->prev;
		}
	}
}
