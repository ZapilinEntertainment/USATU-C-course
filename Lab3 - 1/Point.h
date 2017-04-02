#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point();
		Point(double xpos, double ypos);
		~Point();
		
		virtual void Print(); //polymorphism
	protected:
		double f_xpos,f_ypos;
};

#endif
