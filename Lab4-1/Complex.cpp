#include "Complex.h"

Complex::Complex()
{
	Re=0;
	Im=0;
}

Complex::Complex(double newRe, double newIm)
{
	Re=newRe;
	Im=newIm;
}

Complex::~Complex()
{
}

Complex Complex::operator+( Complex &other ) {  
   return Complex( Re + other.Re, Im + other.Im );  
}  

Complex Complex::operator* (Complex &other)
{
	return (Complex (Re*other.Re-Im*other.Im, Re*other.Im+other.Re*Im));
}




  
