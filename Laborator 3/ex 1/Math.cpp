#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include "Math.h"
#pragma warning(disable:4996)
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	int valoare, s = 0;
	va_list v;
	va_start (v, count);
	for (int i = 0;i < count;i++)
	{
		valoare = va_arg(v, int);
		s = s + valoare;
	}
	va_end(v);
	return s;
}

char* Math::Add(const char* c1, const char* c2)
{
	char* p;
	if (c1 == nullptr || c2 == nullptr)
		return nullptr;
	else
	{
		p = (char*)malloc(strlen(c1) + strlen(c2));
		strcpy(p, c1);
		strcat(p, c2);
	}
	return p;
}