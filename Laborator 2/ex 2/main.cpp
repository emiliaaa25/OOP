#include "student.h"
#include "functii.h"
#include<iostream>
#include<cstring>

using namespace std;
int main()
{	
	student s1, s2;
	s1.set_nume("Emilia");
	s1.set_nota_mate(10);
	s1.set_nota_ist(8);
	s1.set_nota_eng(9);
	s2.set_nume("Serena");
	s2.set_nota_mate(9);
	s2.set_nota_ist(10);
	s2.set_nota_eng(7);

	cout << s1.get_nume();
	cout << compara_nume(s1, s2) << " " << compara_nota_mate(s1, s2) << " " << compara_nota_eng(s1, s2) << " " << compara_nota_ist(s1, s2) << " " << compara_medie(s1, s2);

	return 0;
}