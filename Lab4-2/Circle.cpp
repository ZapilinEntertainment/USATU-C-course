#include "Circle.h"

Circle::Circle()
{
radius=0;
xpos=0;
ypos=0;
}

Circle::Circle(double newXpos, double newYpos,double newRadius)
{
	xpos=newXpos;
	ypos=newYpos;
	if (newRadius>0) radius=newRadius; else radius=0;
}

Circle::~Circle()
{
}
