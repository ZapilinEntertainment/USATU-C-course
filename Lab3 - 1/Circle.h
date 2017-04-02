#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle : public Point
{
	public:
		Circle();
		Circle(double xpos,double ypos,double radius);
		~Circle();
		
		void Print();
		double Square();
	protected:
		double f_radius;
};

#endif
