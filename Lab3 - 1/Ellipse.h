#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Point.h"

class Ellipse : public Point
{
	public:
		Ellipse();
		Ellipse(double xpos,double ypos,double longAxis, double shortAxis);
		~Ellipse();
		
		void Print();
		double Square();
	protected:
		double f_longAxis, f_shortAxis;
};

#endif
