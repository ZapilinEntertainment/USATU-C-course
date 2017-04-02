#include "Ellipse.h"
#include <stdio.h>
#include <cmath>

Ellipse::Ellipse():Point()
{
	f_longAxis=0;
	f_shortAxis=0;
}

Ellipse::Ellipse(double xpos, double ypos,double longAxis,double shortAxis):Point(xpos,ypos)
{
	f_longAxis=longAxis;
	f_shortAxis=shortAxis;
}

Ellipse::~Ellipse()
{
}

void Ellipse::Print()
{
	printf ("Ellipse in (%lf , %lf) with axis %lf and %lf",f_xpos,f_ypos,f_longAxis,f_shortAxis);
}

double Ellipse::Square() {
	return M_PI*f_longAxis*f_shortAxis;
}
