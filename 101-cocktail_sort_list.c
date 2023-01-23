#include "sort.h"

/**
 * swapNodes - swaps the adjacent nodes
 * @left_node: node at left
 * @right_node: node at right
 * @head: double pointer to head of list
 */
void swapNodes(listint_t *left_node, listint_t *right_node, listint_t **head)
{
	listint_t *temp;
	/*reaarrange adjacent pointers of right node*/
	temp = left_node->prev;
	if (temp)
		temp->next = right_node;
	right_node->prev = temp;

	/*adjust links of left node */
	left_node->prev = right_node;
	left_node->next = right_node->next;

	/* finally point back right node to left node */
	right_node->next = left_node;

	/* point back node infront of left to left node */
	if (left_node->next != NULL)
		left_node->next->prev = left_node;
	/* set head node */
	if (right_node->prev == NULL)
		*head = right_node;
	print_list(*head);
}

/**
 * cocktail_sort_list - cocktail sort
 * @list: double pointer to list head
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current, *tail;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = *list, tail = NULL;

	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->next)
			{
				if (current->n > current->next->n)
				{
					swapNodes(current, current->next, list);
					swapped = 1;
				}
				else
					current = current->next;
			}
			if (current->next == NULL)
				tail = current;
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
			else
				tail = tail->prev;
		}
	}
}
