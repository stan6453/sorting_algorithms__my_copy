#ifndef _deck_
#define _deck_

#include <string.h>

/**
 * enum kind_e - Playing card ranks
 *
 * @SPADE: Value of the spade suit
 * @HEART: Value of the heart suit
 * @CLUB:  Value of the club suit
 * @DIAMOND:  Value of the diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
void cocktail_sort_list_value(deck_node_t **list);
void cocktail_sort_list_suit(deck_node_t **list);
void swapNodes(deck_node_t *left_node,
		deck_node_t *right_node, deck_node_t **head);
int get_rank(const char *value);
#endif
