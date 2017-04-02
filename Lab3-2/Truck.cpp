#include "Truck.h"
#include <iostream>

using namespace std;
Truck::Truck():Car()
{
	f_capacity=0;
}
Truck::Truck(Wheel wheel, double cost,string *model, double capacity):Car(wheel,cost,model)
{
	f_capacity=0;
}

Truck::~Truck()
{
}

void Truck::GetInfo()
{
	cout<<"Truck model: "<<&f_model<<endl;
	cout<<"cost: "<<f_cost<<endl;
	cout<<"wheel radius"<<f_wheel.GetRadius()<<endl;
	cout<<"capacity"<<f_capacity<<endl;
}
