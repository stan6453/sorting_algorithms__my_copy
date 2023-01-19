#include "sort.h"

/**
 * swap_nodes - swap linked list nodes
 * @a: first node
 * @b: second node
 * 
 * Return: void
*/
void swap_nodes(listint_t *list_head, listint_t *a, listint_t *b)
{
	listint_t *temp;
	listint_t *head;
	listint_t *tail;
	listint_t temp_i;
	
	temp_i = list_head;
	head = malloc(sizeof(listint_t));
	tail = malloc(sizeof(listint_t));
	

	head = list_head;

	while(temp_i != NULL)
	{
		temp_i = temp_i->next;
	}
	

	while

	if(a->prev != NULL)
	{
		a->prev->next = b;
	}

	if(b->next != NULL)
	{
		b->next->prev = a;
	}

	temp = malloc(sizeof(listint_t));

	temp->prev = a->prev;
	temp->next = a->next;

	a->next = b->next;
	a->prev = b->prev;

	b->next = temp->next;
	b->prev = temp->prev;

	if(head == a)
		head = b;
	else if (head = b)
		head = a;

	if (tail = a)
		tail = b;
	else if (tail = b)
		tail = a;

	
}

/**
 * insertion_sort_list - insertion sort
 * @list: double pointer to head node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *current;
	
	if((*list)->next == NULL || *list == NULL)
		return;
	
	current = (*list)->next;

	while(current != NULL)
	{
		temp = current;

		while(temp->prev != NULL && temp->prev->n > temp->n)
		{
			swap_nodes((*list), temp->prev, temp);
			temp = temp->prev;
		}
		current = temp->next;
	}
}
