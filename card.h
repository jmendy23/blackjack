/*
 *     FileName: card.h
 *     Author: Jake Mendenhall
 *     Due Date: 2/23/16
 *     Description: file that has the enumerated types for
 *					suits and faces, and the structure for a card
 */

#ifndef CARD_H
#define CARD_H

typedef enum
{
	    CLUBS, DIAMONDS, HEARTS, SPADES
} SUITS;

typedef enum
{
	    ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
} FACES;

typedef struct
{
		SUITS suit;
			FACES face;

} card_t;


#endif
