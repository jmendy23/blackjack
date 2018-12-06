/*
	FileName: stack.c
	Author: Jake Mendenhall
	Due Date: 2/23/16
	Description: file that defines functions that main.c
				  uses to play the game of blackjack
*/

#include "card.h"
#include "stack.h"
/*
Parameters:
		stack_t* d - pointer to the deck type
	Returns:
		nothing
	Post Conditions:
		puts cards into the deck
*/
void initDeck(stack_t* d)
{
	int i; //counter for faces
	int j; //counter for suits
	int size=0;

	//for loops to fill up the deck
	for(i=0; i<MAX_SUIT; i++)
	{
		for(j=1; j<MAX_FACE; size++,j++)
		{
			//switch for suits
			switch (i)
			{
            	case CLUBS:
                	d->deck[size].suit = CLUBS;
                	break;
				case DIAMONDS:
					d->deck[size].suit = DIAMONDS;
					break;
				case HEARTS:
					d->deck[size].suit = HEARTS;
					break;
				case SPADES:
					d->deck[size].suit = SPADES;
					break;
			}
			//switch for faces
			switch (j)
			{
				case ACE:
					d->deck[size].face = ACE;
					break;
				case TWO:
					d->deck[size].face = TWO;
                    break;
				case THREE:
                    d->deck[size].face = THREE;
                    break;
                case FOUR:
                    d->deck[size].face = FOUR;
                    break;
                case FIVE:
                    d->deck[size].face = FIVE;
                    break;
                case SIX:
                    d->deck[size].face = SIX;
                    break;
                case SEVEN:
                    d->deck[size].face = SEVEN;
                    break;
                case EIGHT:
                    d->deck[size].face = EIGHT;
                    break;
                case NINE:
                    d->deck[size].face = NINE;
                    break;
                case TEN:
                    d->deck[size].face = TEN;
                    break;
                case JACK:
                    d->deck[size].face = JACK;
                    break;
                case QUEEN:
                    d->deck[size].face = QUEEN;
                    break;
                case KING:
                    d->deck[size].face = KING;
                    break;
			}
		}
	}
	//sets top to 52
	//the shuffles deck
	d->top = MAX_DECK;
	shuffleDeck(d);
}

/*
	shuffleDeck
	Parameters:
		stack_t* d --- pointer to the deck
	Returns:
		nothing
	Post Conditions:
		shuffles the whole deck.
*/

void shuffleDeck(stack_t* d)
{
	int i;//index-card on top
	int j;//index-random card
	card_t temp;//temp for swap
	
	//for loop sets i to the card on top of deck
	//and j is a random card in the deck
	//then it swaps them to make it shuffle..
	//goes through MAX_DECK times
	for(i=0; i < MAX_DECK; i++)
	{
		//call the rand function using %MAX_DECK to
		//go through 0-51
		j=rand()%MAX_DECK;
		//swaps cards
		temp = d->deck[i];
		d->deck[i] = d->deck[j];
		d->deck[j] = temp;
	}
}

/*
	pushDeck
	Parameters:
		stack_t* d --- pointer to the deck
		card_t c --- the actual card
	Returns:
		nothing
	Post Conditions:
		nothing, i am not using this function
*/ 

void pushDeck(stack_t* d, card_t c)
{
	//if stack is not full put card on top 
	//of deck (stack)
	//else: it is full
	if(d->top < MAX_DECK-1)
	{
		d->deck[d->top]=c;
		d->top++;
	}
	else
	{
		printf("stack is full");
	}
}

/*
	popDeck
	Parameters:
		stack_t* d --- pointer to the deck
		card_t* c --- pointer to the card
	Returns:
		the card that is on top of deck
	Post Conditions:
		card is removed from top and top--
*/

void popDeck(stack_t* d, card_t* c)
{
	//if stack is not empty draw card off top
	//else deck is empty
	if(d->top > 0)
	{
		*c = d->deck[d->top-1];
		d->top--;
	}
	else
	{
		c=NULL;
	}
}

/*
	isMoneyInteger
	Parameters:
		none
	Returns:
		return -1 if it isnt an integer
		return money if it is an integer
	Post Conditions:
		money is set for the while loop in
		main.c
*/

int isMoneyInteger()
{
	char buffer[MAX_BET];
	int i;
	int money=0;

	//ask for money
	//read in as a c-string
	printf("Enter money (0 to end): ");
	fgets(buffer, MAX_BET, stdin);
	//check to see if each char is an 
	//integer or not
	for(i=0; buffer[i]!= '\n'; i++)
	{
		if(!isdigit(buffer[i]))
		{
			printf("Money must be an integer.\n");
			return NON_INT;
		}
	}
	//if integer change buffer to int
	//and return it
	money = atoi(buffer);
	return money;
}

/*
	isBetInt
	Parameters:
		none
	Returns:
		returns -1 if bet isnt an integer
		returns bet if bet is an integer
	Post Conditions:
		bet now has an a number for main.c
*/ 

int isBetInt()
{
	char buffer[MAX_BET];
	int i;
	int bet=0;

	//ask for bet and read in as c-string
	printf("Enter bet (0 to end): ");
	fgets(buffer, MAX_BET, stdin);
	
	//see if each char is an integer or not
	//if not return -1
	for(i=0; buffer[i] != '\n'; i++)
	{
		if(!isdigit(buffer[i]))
		{
			printf("Bet must be an integer.\n");
			return NON_INT;
		}
	}
	//if integers change into an int 
	//and return bet
	bet = atoi(buffer);
	return bet;
}

/*
	cardPopped
	Parameters:
		card_t* c --- pointer to the card that was dealt
	Returns:
		nothing
	Post Conditions:
		gives the name of the card for printHand
*/ 

void cardPopped(card_t* c)
{
	//switch for faces
	switch(c->face)
	{
		case ACE:
			printf("[Ace of ");
			break;
		case TWO:
			printf("[Two of ");
			break;
		case THREE:
			printf("[Three of ");
			break;
		case FOUR:
			printf("[Four of ");
			break;
		case FIVE:
			printf("[Five of ");
			break;
		case SIX:
			printf("[Six of ");
			break;
		case SEVEN:
			printf("[Seven of ");
			break;
		case EIGHT:
			printf("[Eight of ");
			break;
		case NINE:
			printf("[Nine of ");
			break;
		case TEN:
			printf("[Ten of ");
			break;
		case JACK:
			printf("[Jack of ");
			break;
		case QUEEN:
			printf("[Queen of ");
			break;
		case KING:
			printf("[King of ");
			break;
	}
	//switch for suits
	switch(c->suit)
	{
		case CLUBS:
			printf("Clubs] ");
			break;
		case DIAMONDS:
			printf("Diamonds] ");
			break;
		case HEARTS:
			printf("Hearts] ");
			break;
		case SPADES:
			printf("Spades] ");
			break;
	}
}

/*
	printHand
	Parameters:
		player_t* p --- pointer to the player_t struct
	Returns:
		nothing
	Post Conditions:
		prints out each card in the hand
*/ 

void printHand(player_t* p)
{
	int i;
	//for every card print out the acutal
	//name of the card
	for(i=0; i < p->numCards; i++)
	{
		cardPopped(&p->hand[i]);
	}
}

/*
	countScore
	Parameters:
		player_t *p --- pointer to the player_t struct
	Returns:
		nothing
	Post Conditions:
		sets the score of the hand that was dealt
		to either the user or dealer
*/ 

void countScore(player_t* p)
{
	//p->hand[p->numCards-1] --- because the location of the card sent 
	//to this function is one less than the numCards in the deck
	
	//if the card in the array is a jack, queen, or king
	//make score = score + 10
	if(p->hand[p->numCards-1].face >= 11)
	{
		p->score += 10;
	}
	//if card is an ace make score = score + 11
	//and increment number of aces in the hand
	else if(p->hand[p->numCards-1].face == ACE)
	{
		p->score += 11;
		p->aces++;
	}
	//for every other card 2-10 score = score + the card face
	else
	{
		p->score += p->hand[p->numCards-1].face;
	}
}


