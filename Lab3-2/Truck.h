#ifndef TRUCK_H
#define TRUCK_H

#include "Car.h"
#include <string>

class Truck : public Car
{
	public:
		Truck();
		Truck(Wheel wheel, double cost,std::string *model, double capacity);
		~Truck();
		void GetInfo();
	protected:
		double f_capacity;
};

#endif
