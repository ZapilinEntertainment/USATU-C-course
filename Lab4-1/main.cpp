#include <iostream>
#include "Complex.h"
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	using namespace std;
	Complex A,B,S,P;
	cout<<"A: ";
	cin>>A;
	cout<<"B: ";
	cin>>B;
	S=A+B;
	P=A*B;
	cout<<"A+B = "<<S<<endl;
	cout<<"A*B = "<<P;
	_getch();
	return 0;
}
