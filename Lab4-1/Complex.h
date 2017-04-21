#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>  
using namespace std; 

class Complex
{
	friend ostream &operator<<(ostream& os, const Complex& val)  
	{  
	    os << val.Re<<'+'<<val.Im<<'i';  
	    return os;  
	}   
	friend istream &operator>>(istream &stream, Complex &val)
	{
	stream >> val.Re >> val.Im;
	return stream;
	} 
	
	public:
	double Re,Im;
		Complex();
		Complex(double Re,double Im);
		~Complex();
	
		Complex operator+( Complex &other ); 
		Complex operator*( Complex &other ); 
		
};

#endif
