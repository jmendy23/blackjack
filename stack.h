/*
    FileName: stack.h
	Author: Jake Mendenhall
    Due Date: 2/23/16
	Description: file that has structs and prototypes for functions used 
	in main.c and defined in stack.c
*/ 

#ifndef STACK_H
#define STACK_H
#include <string.h>X_HAND 12 // max number of cards in a hand

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "card.h"

#define MAX_DECK 52
#define MAX_SUIT 4
#define MAX_FACE 14
#define MAX_BET 81 // max chars in a bet 
#define MAX_HAND 12 // max number of cards in a hand
#define NON_INT  -1 //if -1 is returned means money or bet wasnt 
#define MAX_SCORE 21 //max score player can have in a single 
#define HIT_DEALER 17 //constant for when the dealer should get 

typedef struct
{
		card_t deck[MAX_DECK];
		int top; // index of top item on stack
} stack_t;

typedef struct
{
	int numCards;
	card_t hand[MAX_HAND];
	int bet;
	int money;
	int score;
	int aces;
} player_t;

void initDeck(stack_t* deck);
void shuffleDeck(stack_t* deck);
void pushDeck(stack_t* deck, card_t c);
void popDeck(stack_t *deck, card_t* c);
int isMoneyInteger();
int isBetInt();
void cardPopped(card_t* c);
void printHand(player_t* p);
void countScore(player_t* p);


#endif
