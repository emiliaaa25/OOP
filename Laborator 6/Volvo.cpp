#include "Volvo.h"
#include "Car.h"
#include "Circuit.h"
using namespace std;
int Volvo::set_fuel_cap(int x)
{
	if (x == 0)
	{
		this->fuel_cap = 60 ;
		return fuel_cap;
	}
	if (x == 1)
	{
		this->fuel_cap = 40;
		return fuel_cap;
	}
	if (x == 2)
	{
		this->fuel_cap = 70 ;
		return fuel_cap;
	}
}

int Volvo::set_fuel_cons(int x)
{
	if (x == 0) {
		this->fuel_cons = 50;
		return fuel_cons;
	}
	if (x == 1) {
		this->fuel_cons = 60;
		return fuel_cons;
	}
	if (x == 2) {
		this->fuel_cons = 90;
		return fuel_cons;
	}
}

int Volvo::set_speed(int x)
{
	if (x == 0)
	{
		this->speed = 50;
		return speed;
	}
	if (x == 1)
	{
		this->speed = 30;
		return speed;
	}
	if (x == 2)
	{
		this->speed = 150;
		return speed;
	}
}

void Volvo::afiseaza()
{
	cout << "Volvo: ";
}
