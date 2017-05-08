#include "Deck.h"
#include<iostream>
Deck::Deck()
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
	cardsLeft = 54;
}

Deck::~Deck()
{
}

void Deck::GetCard() {
	if (cardsLeft>0) {
		cards[cardsLeft-1].Print();
		cardsLeft--;
	}
	else std::cout<<"no cards"<<std::endl;
}
