/* #include "sort.h" */
#include "deck.h"


/**
 * sort_deck - sorts a deck of cards.
 * @deck: double pointer to the head of the deck of cards
 * Note: we assume thta there are 52 cards in the linked list
 * Return: 0 if program exited without error
 */
void sort_deck(deck_node_t **deck)
{

	cocktail_sort_list_value(deck);
	cocktail_sort_list_suit(deck);
}


/**
 * swapNodes - swaps the adjacent nodes
 * @left_node: node at left
 * @right_node: node at right
 * @head: double pointer to head of list
 */
void swapNodes(deck_node_t *left_node, deck_node_t *right_node,
		deck_node_t **head)
{
	deck_node_t *temp;
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
}

/**
 * cocktail_sort_list_value - cocktail sort
 * @list: double pointer to list head
 *	0: sort by rank
 *	1: sort by suit
 */
void cocktail_sort_list_value(deck_node_t **list)
{
	int swapped __attribute__((unused)) = 1;
	deck_node_t *current __attribute__((unused));
	deck_node_t *tail __attribute__((unused)) = NULL;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->next)
			{
				if (get_rank(current->card->value) > get_rank(current->next->card->value))
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
			if (get_rank(tail->prev->card->value) > get_rank(tail->card->value))
			{
				swapNodes(tail->prev, tail, list);
				swapped = 1;
			}
			else
				tail = tail->prev;
		}
	}
}


/**
 * cocktail_sort_list_suit - cocktail sort
 * @list: double pointer to list head
 *	0: sort by rank
 *	1: sort by suit
 */
void cocktail_sort_list_suit(deck_node_t **list)
{
	int swapped __attribute__((unused)) = 1;
	deck_node_t *current __attribute__((unused));
	deck_node_t *tail __attribute__((unused)) = NULL;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->next)
			{
				if (current->card->kind > current->next->card->kind)
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
			if (tail->prev->card->kind > tail->card->kind)
			{
				swapNodes(tail->prev, tail, list);
				swapped = 1;
			}
			else
				tail = tail->prev;
		}
	}
}

/**
 * get_rank - gets the numeric value of a card's rank
 * @value: string value to return the rank for
 * Return: 0 if program exited without error
 */
int get_rank(const char *value)
{
	int i;
	char *ranks[] = {"just_here_for_padding_lol", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};

	for (i = 1; i < 13; i++)
	{
		if (strcmp(value, ranks[i]) == 0)
			return (i);
	}
	return (0);
}
