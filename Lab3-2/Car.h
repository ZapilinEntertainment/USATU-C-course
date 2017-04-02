#ifndef CAR_H
#define CAR_H
#include "Wheel.h"
#include <string>

class Car
{
	public:
		Car();
		Car(Wheel wheel, double cost, std::string *model);
		~Car();
		virtual void GetInfo();
	protected:
		Wheel f_wheel;
		double f_cost;
		std::string *f_model;
};

#endif
