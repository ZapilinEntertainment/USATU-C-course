#ifndef CARD_H
#define CARD_H

enum CardRank {
	Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Joker
};
enum CardSuit {
	Hearts, Diamonds, Clubs, Spades
};

class Card
{
	
	public:
		Card();
		Card(CardRank r, CardSuit s);
		~Card();
		void Invert();
		void FaceUp();
		void Print();
		
		bool opened;
	protected:
		CardRank rank;
		CardSuit suit;
};

#endif
