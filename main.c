/*
 * me: main.c
    Author: Jake Mendenhall
    Due Date: 2/23/16
    Description: a blackjack game that continues until money or bet = 0
				 using all the rules of blackjack except only has one deck
				 of cards
*/

#include "card.h"
#include "stack.h"

int main()
{
	srand(time(NULL)); // making the random function actually be random everytime
	int moneyAmount; // variable for how much money
	int betAmount; // variable for  bet
	stack_t deck; // variable to fill up the deck
	card_t cardItem; // variable for what card was dealt
	char hitMe;	// char for H or h
	player_t user; // user struct
	player_t dealer; // dealer struct
	char junk; // char that gets the newline after hitMe
	int i; //variable for  for loops

	printf("Welcome to my Black Jack Game\n");
	//puts cards in deck, shuffles deck, and sets top to MAX_DECK
	initDeck(&deck);

	//asks user for how much money they have
	//if non integer the function returns -1
	//then calls the function again...once integer
	//it returns the money amount
	user.money=isMoneyInteger();
	while(user.money == NON_INT)
	{
		user.money = isMoneyInteger();
	}
	//while money is greater than 0
	//the game continues
	while(user.money > 0)
	{
		//sets everything to 0 so the game will work
		//properly over and over
		dealer.numCards = 0;
		user.numCards = 0;
		dealer.score = 0;
		user.score = 0;
		dealer.aces = 0;
		user.aces = 0;

		printf("Player chip stack: $%d\n", user.money);
		//gets the bet amount from user...same as isMoneyIneger()
		//if bet > money asks for the user to make a new bet
		user.bet=isBetInt();
		while(user.bet == NON_INT)
		{
			user.bet=isBetInt();
		}
		while(user.bet > user.money)
		{
			printf("You can't bet more than you have\n");
			user.bet=isBetInt();
		}
		//if bet = 0 breaks out of while loop
		//and program ends
		if(user.bet == 0)
		{
			break;
		}

		printf("Bet amount: $%d\n",user.bet);
	
		//deals the 1st  card to the user
		//puts the card to the user's hand
		//increments the numCards
		//then counts the score of the user's hand
		popDeck(&deck, &cardItem);
		user.hand[user.numCards] = cardItem;
		user.numCards++;
		countScore(&user);

		//deals the 1st card to the dealer
		//puts the card to the dealer's hand
		//increments the numCards
		//then counts the score of the dealer's hand
		popDeck(&deck, &cardItem);
		dealer.hand[dealer.numCards] = cardItem;
		dealer.numCards++;
		countScore(&dealer);	
	
		//deals the 2nd card to the user
		//puts the card to the user's hand
		//increments the numCards
		//then counts the score of the user's hand
		popDeck(&deck, &cardItem);
		user.hand[user.numCards] = cardItem;
		user.numCards++;
		countScore(&user);

		//deals the 2nd card to the dealer
		//puts the card to the dealer's hand
		//increments the numCards
		//then counts the score of the dealer's hand
		popDeck(&deck, &cardItem);
		dealer.hand[dealer.numCards] = cardItem;
		dealer.numCards++;
		countScore(&dealer);	
		
		//prints the first card that the dealer has
		printf("Dealer: ");
		cardPopped(&dealer.hand[0]);
		printf("\n");
		
		//prints the users cards
		printf("Player: ");
		printHand(&user);
		printf("\n");
		//prints user card score
		printf("Player total: %d\n", user.score);

		//loop for hit or stay
		//if hit the user is dealt another card
		//puts that card into the user's hand
		//increments numCards
		//then counts the score of the user's hand
		//last prints out the whole hand and the score
		//if stay it just goes to see if the dealer is
		//dealt more cards
		printf("(H)it or (S)tay: ");
		scanf("%c",&hitMe);
		//gets the newline
		junk = getc(stdin);

		while(hitMe == 'h' || hitMe == 'H')
		{
	    	popDeck(&deck, &cardItem);
	    	user.hand[user.numCards] = cardItem;
	    	user.numCards++;
	    	countScore(&user);
			//if user has an ace and over 21 
			//score = score - 10 and the
			//number of aces is decremented
			for(i=0; i<user.numCards; i++)
			{
				if(user.aces > 0 && user.score > MAX_SCORE)
				{
					user.score-=10;
					user.aces--;		
				}
			}
			//prints the first card that the dealer has
			printf("Dealer: ");
			cardPopped(&dealer.hand[0]);
			printf("\n");
			//print player's card and score
			printf("Player: ");
			printHand(&user);
			printf("\n");
			printf("Player total: %d\n", user.score);
			//if user's score is more than 21
			//exit while loop since  user cant hit anymore
			if(user.score > MAX_SCORE)
			{
				break;
			}
			//reinitialize while loop
			printf("(H)it or (S)tay: ");
			scanf("%c", &hitMe);
			// gets the newline
			junk = getc(stdin);
		}
		
		//if soft 17 for the dealer..the dealer
		//is dealt another card
		for(i=0; i<dealer.numCards; i++)
		{
			if((dealer.hand[i].face == ACE && dealer.hand[i+1].face == SIX) || 
			   (dealer.hand[i].face == SIX && dealer.hand[i+1].face == ACE))
			{
	    	    popDeck(&deck, &cardItem);
	    	    dealer.hand[dealer.numCards] = cardItem;
	    	    dealer.numCards++;
	    	    countScore(&dealer);
				//if dealer has an ace and over 21 
				//score = score - 10 and the number
				//of aces is decremented
				if(dealer.aces > 0 && dealer.score > MAX_SCORE)
				{
					dealer.score-=10;
					dealer.aces--;		
				}
			}
		}
		//while the dealer's score is less than 17
		//dealer is dealt another card
		while(dealer.score < HIT_DEALER)
		{
			popDeck(&deck, &cardItem);
			dealer.hand[dealer.numCards] = cardItem;
			dealer.numCards++;
			countScore(&dealer);	
			for(i=0; i<dealer.numCards; i++)
			//if dealer has an ace and over 21 
			// score = score - 10 and the number
			//of aces is decremented
			{
				if(dealer.aces > 0 && dealer.score > MAX_SCORE)
				{
					dealer.score-=10;
					dealer.aces--;		
				}
			}
		}

		//prints the whole dealer's hand
		printf("Dealer: ");
		printHand(&dealer);
		printf("\n");
		
		//prints the whole player's hand
		printf("Player: ");
		printHand(&user);
		printf("\n");
	
		//if user score > 21 player busts and dealer's hand
		// is less than 21.. player loses money = money - bet
		if(user.score > MAX_SCORE && dealer.score <= MAX_SCORE)
		{
			printf("Player busted %d to %d\n", user.score, dealer.score);
			user.money-=user.bet;
		}
		//if user score is > dealer score && user score <= 21
		//player wins.. and money = money + bet
		else if(user.score > dealer.score && user.score <=MAX_SCORE)
		{
			printf("Player won: %d to %d\n", user.score, dealer.score);
			user.money+=user.bet;
		}
		//if dealer score is > user score && dealer score <= 21
		//player loses.. and money = money - bet
		else if(user.score < dealer.score && dealer.score <= MAX_SCORE)
		{
			printf("Player lost: %d to %d\n", user.score, dealer.score);
			user.money-=user.bet;
		}
		//if dealer score is >  21 dealer busts and player is <= 21
		//and player wins.. money = money + bet
		else if(dealer.score > MAX_SCORE && user.score <= MAX_SCORE)
		{
			printf("Dealer busted %d to %d\n", user.score, dealer.score);
			user.money+=user.bet;
		}
		//if dealer and user bust.. its a push
		//money = money
		else if(dealer.score > MAX_SCORE && user.score > MAX_SCORE)
		{
			printf("Player and Dealer busted: %d to %d\n", user.score, dealer.score);
			user.money=user.money;
		}
		//if dealer score = user score..its a push
		//money = money
		else //(dealer.score == user.score)
		{
			printf("Player Pushed: %d to %d\n", user.score, dealer.score);
			user.money=user.money;
		}
	}
	//print chip stack when user quits or runs out of money
	//game ends
	printf("Player chip stack: $%d\n", user.money);

	return 0;
}

