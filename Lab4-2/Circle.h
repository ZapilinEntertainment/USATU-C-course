#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>

using namespace std;

class Circle
{
	friend Circle operator/ (Circle A, Circle B);
	friend ostream& operator<<(ostream& os, const Circle& c)  
	{  
    os << "Circle in ("<<c.xpos<<';'<<c.ypos<<") with radius "<<c.radius;  
    return os;  
	} 
	friend istream& operator>> ( istream& is, Circle& c )  
	{  
	   is >> c.xpos >> c.ypos >> c.radius;  
	   return is;  
	}  
 
	
	public:
		Circle();
		Circle(double xpos, double ypos,double radius);
		~Circle();
	protected:
		double xpos,ypos,radius;
};

#endif
