#include "Circle.h"
#include <stdio.h>
#include <cmath>
Circle::Circle():Point()
{
	f_radius=0;
}
Circle::Circle(double xpos,double ypos,double radius):Point(xpos,ypos)
{
	f_radius=radius;
}

Circle::~Circle()
{
}

void Circle::Print () 
{
	printf ("Circle in (%lf , %lf) with radius %lf",f_xpos,f_ypos,f_radius);
}
double Circle::Square()
{
	return M_PI*f_radius*f_radius;
}
