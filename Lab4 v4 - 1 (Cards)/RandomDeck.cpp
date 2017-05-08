#include "RandomDeck.h"
#include <stdlib.h>
#include <time.h>
RandomDeck::RandomDeck():Deck()
{
	cards = new Card[54];
	for (int i = 0; i< 13; i++)
	{
		cards[i] = Card((CardRank)i,(CardSuit)0); //Hearts
		cards[i+13] = Card((CardRank)i,(CardSuit)1); //Diamonds
		cards[i+26] = Card((CardRank)i,(CardSuit)2); //Clubs
		cards[i+39] = Card((CardRank)i,(CardSuit)3); //Spades
	}
	cards[52] = Card((CardRank)13,(CardSuit)0);
	cards[53] = Card((CardRank)13,(CardSuit)2);
	
	Card * new_deck = new Card[54];
	srand(time(NULL));
	int i=0;
	for (i; i < 53; i++)
	{
		int lastIndex = 53-i;
		Card buferred;
		int p = rand()%lastIndex;
		if (p != lastIndex) {
			buferred = cards[lastIndex];
			cards[lastIndex] = cards[p];
			new_deck[i] = cards[p];
			cards[p] = buferred;
		}
		else new_deck[i]=cards[p];
	}
	new_deck[53] = cards[0];
	delete[] cards;
	cards = new Card[54];
	for (i =0; i<54; i++) {
		cards[i] = new_deck[i];
	}
	delete[] new_deck;
	cardsLeft = 54;
}

RandomDeck::~RandomDeck()
{
}


