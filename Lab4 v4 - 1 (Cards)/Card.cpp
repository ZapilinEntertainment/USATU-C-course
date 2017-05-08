#include "Card.h"
#include <string>
#include <iostream>
Card::Card()
{
	rank = Two;
	suit = Hearts;	
	opened = false;
}

Card::Card(CardRank r, CardSuit s) 
{
	rank = r;
	suit = s;
	opened = true;
}

void Card::Invert() {
	opened = !opened;
}

void Card::FaceUp() {
	opened = true;
}

void Card::Print() {
std::string output="";
	switch (rank) {
		case 0: output+="Two";break;
		case 1: output+="Three";break;
		case 2: output+="Four";break;
		case 3: output+="Five";break;
		case 4: output+="Six";break;
		case 5: output+="Seven";break;
		case 6: output+="Eight";break;
		case 7: output+="Nine";break;
		case 8: output+="Ten";break;
		case 9: output+="Jack";break;
		case 10: output+="Queen";break;
		case 11: output+="King";break;
		case 12: output+="Ace";break;
		case 13: output+="Joker";break;
	}
	output+=" of ";
	if (rank != 13) {
		switch (suit) {
			case 0: output+="Hearts";break;
			case 1: output+="Diamonds";break;
			case 2: output+="Clubs";break;
			case 3: output+="Spades";break;
		}
	}
	else {
		if (suit<2) output+="Red";
		else output+="Black";
	}
	std::cout<<output<<std::endl;
}

Card::~Card()
{
}
