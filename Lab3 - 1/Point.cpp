#include "Point.h"
#include <stdio.h>

Point::Point(double xpos, double ypos)
{
	f_xpos=xpos;
	f_ypos=ypos;
	//printf("%lf %lf",&xpos,&ypos);
}
Point::Point()
{
	f_xpos=0;
	f_ypos=0;
}

Point::~Point()
{
}

void Point::Print () 
{
	printf ("Point ( %lf , %lf )",f_xpos,f_ypos);
}
