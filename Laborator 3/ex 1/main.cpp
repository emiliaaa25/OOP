#include<stdio.h>
#include<iostream>
#include "Math.h"

int main()
{
	Math m;
	std::cout << m.Add(4,5) << " " << m.Add(4,6,9) << " " << m.Add(3.5, 6.7) << " " << m.Add(4.6, 5.7, 7.8) << std::endl;
	std::cout << m.Mul(4, 5) << " " << m.Mul(4, 6, 9) << " " << m.Mul(3.5, 6.7) << " " << m.Mul(4.6, 5.6, 7.8) << std::endl;
	std::cout << m.Add(3, 7, 9, 3)<<std::endl;
	std::cout << m.Add("mare","mic");
	return 0;
}