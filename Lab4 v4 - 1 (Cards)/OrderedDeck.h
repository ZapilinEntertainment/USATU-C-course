#ifndef ORDEREDDECK_H
#define ORDEREDDECK_H

#include "Deck.h"

class OrderedDeck : public Deck
{
	public:
		OrderedDeck();
		~OrderedDeck();
	protected:
		int cardsLeft;
};

#endif
