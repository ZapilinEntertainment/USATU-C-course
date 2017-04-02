#include "Wheel.h"

Wheel::Wheel()
{
	f_radius=0;
}
Wheel::Wheel(double radius)
{
	f_radius=radius;
}

Wheel::~Wheel()
{
}

double Wheel::GetRadius()
{
	return f_radius;
}
