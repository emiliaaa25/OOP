#include "student.h"
#include<iostream>
#include<iostream>

void student::set_nume(const char *a)
{
	strcpy(name, a);
}

char* student::get_nume()
{
	return name;
}

void student::set_nota_mate(float x)
{
	if (x >= 1 && x <= 10)
		this->mate = x;
	else
		this->mate = 0;
}
float student::get_nota_mate()
{
	return mate;
}
void student::set_nota_eng(float x)
{
	if (x >= 1 && x <= 10)
		this->eng = x;
	else
		this->eng = 0;
}
float student::get_nota_eng()
{
	return eng;
}
void student::set_nota_ist(float x)
{
	if (x >= 1 && x <= 10)
		this->ist = x;
	else
		this->ist = 0;
}
float student::get_nota_ist()
{
	return ist;
}

float student::medie()
{
	return (get_nota_eng() + get_nota_ist() + get_nota_mate()) / 3;
}