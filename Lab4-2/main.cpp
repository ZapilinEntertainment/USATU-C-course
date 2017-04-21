#include <iostream>
#include "Circle.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Circle operator/ (Circle A, Circle B)
{
	return (Circle(A.xpos/B.xpos,A.ypos/B.ypos,A.radius));
}

using namespace std;
int main(int argc, char** argv) {
Circle A,B,Q;//quotient
		cout<<"Circle A: ";
		cin>>A;
		cout<<"Circle B: ";
		cin>>B;
		Q=A/B;
		cout<<Q;
	return 0;
}
