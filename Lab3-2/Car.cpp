#include "Car.h"
#include <iostream>

using namespace std;
Car::Car()
{
	f_wheel=Wheel();
	f_cost=0;
}
Car::Car(Wheel wheel, double cost,string *model)
{
	f_wheel=wheel;
	f_cost=cost;
	f_model=model;
}

void Car::GetInfo()
{
	cout<<"Auto model: "<<&f_model<<endl;
	cout<<"cost: "<<f_cost<<endl;
	cout<<"wheel radius"<<f_wheel.GetRadius()<<endl;
}

Car::~Car()
{
}
