
#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include <ctime>
#include <stdarg.h>

Sort::Sort(int number, ...) : v(new int[number]), count(number) {
	va_list args;
	va_start(args, number);
	for (int i = 0; i < number; i++)
		v[i] = va_arg(args, int);
	va_end(args);
}

	Sort::Sort(int n, int max, int min)
	{
		this->count = n;
		this->v = new int[this->count];
		time_t t;
		srand((unsigned)time(&t));
		for (int i = 0; i < n; i++)
		{
			this->v[i] = min + rand() % (min - max + 1);

		}

	}

	Sort::Sort(const char* str) {
		this->count = 0;
		char* s = new char[strlen(str) + 1];
		strcpy(s, str);

		char* p = strtok(s, ",");
		while (p) {
			count++;
			p = strtok(nullptr, ",");
		}
		delete[] s;
		s = new char[strlen(str) + 1];
		strcpy(s, str);
		v = new int[count];

		p = strtok(s, ",");
		int i = 0;
		while (p) {
			v[i++] = atoi(p); // converteste sirul p la un int
			p = strtok(nullptr, ",");
		}
		delete[] s;
	}

	Sort::Sort() : v(new int[6] {1, 2, 3, 4, 5, 6})
	{
		this->count = 6;
	}

	

	void Sort::BubbleSort(bool ascendent)
	{
		bool ok = false;
		while (ok == false)
		{
			ok = true;
			for (int i = 0; i < this->count - 1; i++)
				if (ascendent == true)
					if (this->v[i] > this->v[i + 1])
					{
						int aux = this->v[i];
						this->v[i] = this->v[i + 1];
						this->v[i + 1] = aux;
						ok = false;
					}
					else
						if (this->v[i] < this->v[i + 1])
						{
							int aux = this->v[i];
							this->v[i] = this->v[i + 1];
							this->v[i + 1] = aux;
							ok = false;
						}

		}

	}

	void Sort::InsertSort(bool ascendent)
	{
		for (int i = 1; i < this->count; i++)
		{
			int p = i;

			while (p > 0 && ((ascendent == true && this->v[p] < this->v[p - 1]) || (ascendent == false && this->v[p] > this->v[p - 1])))
			{
				int aux = this->v[p];
				this->v[p] = this->v[p - 1];
				this->v[p - 1] = aux;
				p--;
			}
		}
		ascendent = true;
	}

	void Sort::QuickSort(bool ascendent)
	{
		QuickSort(0, this->count, ascendent);

	}

	void Sort::QuickSort(int st, int dr, bool ascendent)
	{
		if (st < dr)
		{
			//pivotul este inițial v[st]
			int m = (st + dr) / 2;
			int aux = this->v[st];
			this->v[st] = this->v[m];
			this->v[m] = aux;
			int i = st, j = dr, d = 0;
			while (i < j)
			{
				if (ascendent)
				{
					if (this->v[i] > this->v[j])
					{
						aux = this->v[i];
						this->v[i] = this->v[j];
						this->v[j] = aux;
						d = 1 - d;
					}
					i += d;
					j -= 1 - d;
				}
				else
				{
					if (this->v[i] < this->v[j])
					{
						aux = this->v[i];
						this->v[i] = this->v[j];
						this->v[j] = aux;
						d = 1 - d;
					}
					i += d;
					j -= 1 - d;

				}

			}
			QuickSort(st, i - 1, ascendent);
			QuickSort(i + 1, dr, ascendent);
		}

	}


	int  Sort::GetElementsCount()
	{
		return  this->count;
	}

	int  Sort::GetElementFromIndex(int index)
	{
		if (index >= 0 && index <= count)
			return v[index];
		return -1;
	}

	void Sort::Print()
	{
		for (int i = 0; i < count;i++) {
			printf("%d\n", v[i], "");

			printf("\n");
		}


 }