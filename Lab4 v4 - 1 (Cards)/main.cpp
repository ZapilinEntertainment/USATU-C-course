#include <iostream>
#include "OrderedDeck.h"
#include "RandomDeck.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	std::cout<<"print 1 for random deck, 0 for ordered deck";
	int x;
	std::cin>>x;
	if (x==1) {
	RandomDeck od = RandomDeck();
	for (int i=0; i<54; i++) {
		od.GetCard();
	}
	}
	if (x==0) {
		OrderedDeck od = OrderedDeck();
	for (int i=0; i<54; i++) {
		od.GetCard();
	}
	}
	return 0;
}
