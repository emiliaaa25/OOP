#include "functii.h"
#include<cstring>

int compara_nume(student s1, student s2)
{
	if (strcmp(s1.get_nume(), s2.get_nume()) == 0)
		return 0;
	else
		if (strcmp(s1.get_nume(), s2.get_nume()) == 1)
			return 1;
		else
			return -1;
}
int compara_nota_mate(student s1, student s2)
{
	if (s1.get_nota_mate() == s2.get_nota_mate())
		return 0;
	else
		if (s1.get_nota_mate() > s2.get_nota_mate())
			return 1;
		else
			return -1;
}

int compara_nota_eng(student s1, student s2)
{
	if (s1.get_nota_eng() == s2.get_nota_eng())
		return 0;
	else
		if (s1.get_nota_eng() > s2.get_nota_eng())
			return 1;
		else
			return -1;
}

int compara_nota_ist(student s1, student s2)
{
	if (s1.get_nota_ist() == s2.get_nota_ist())
		return 0;
	else
		if (s1.get_nota_ist() > s2.get_nota_ist())
			return 1;
		else
			return -1;
}

int compara_medie(student s1, student s2)
{
	if (s1.medie() == s2.medie())
		return 0;
	else
		if (s1.medie() > s2.medie())
			return 1;
		else
			return -1;
}