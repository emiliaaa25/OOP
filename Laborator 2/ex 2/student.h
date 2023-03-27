#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
class student
{
private:
	float mate;
	float eng;
	float ist;
	char name[256];
public:
	void  set_nume(const char *a);
	char* get_nume();
	void set_nota_mate(float x);
	float get_nota_mate();
	void set_nota_eng(float x);
	float get_nota_eng();
	void set_nota_ist(float x);
	float get_nota_ist();

	float medie();

};