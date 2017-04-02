#include <iostream>
#include "Circle.h"
#include "Ellipse.h"



int main(int argc, char** argv) {
Ellipse c=Ellipse(15,16,17,18);
c.Print();
printf("\n");
Circle c2=Circle(15,16,17);
c2.Print();
	return 0;
}
