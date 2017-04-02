#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
	public:
		Wheel();
		Wheel (double radius);
		~Wheel();
		double GetRadius();
	protected:
		double f_radius;
};

#endif
