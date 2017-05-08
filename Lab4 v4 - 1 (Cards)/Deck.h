#ifndef DECK_H
#define DECK_H
#include "Card.h"
class Deck
{
	public:
		Deck();
		~Deck();
		void GetCard();
	protected:
		Card * cards;
		int cardsLeft;
};

#endif
