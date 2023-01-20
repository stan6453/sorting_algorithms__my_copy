#include "sort.h"

/**
 * insertion_sort_list - insertion sort on doubly linked list
 * @list: double pointer to list head
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			/* temp node to hold current */
			listint_t *temp = current;
			/* adjust adjacent links to current */
			if (temp->next)
				temp->next->prev = current->prev;
			temp->prev->next = current->next;
			/* change current to previous node */
			current = current->prev;
			/*adjust temp node to point to previous current */
			temp->next = current;
			temp->prev = temp->prev->prev;
			/* point back current, which is now move behind to temp */
			current->prev = temp;
			/* adjust temp prev */
			if (temp->prev)
				temp->prev->next = temp;
			/* adjust head node */
			if (temp->prev == NULL)
				(*list) = temp;
			/* print list */
			print_list(*list);
			/* move back list */
			current = current->prev;
		}
		current = current->next;
	}
}
