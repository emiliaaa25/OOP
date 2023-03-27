#include "NumberList.h"
#include <iostream>

using namespace N;
using namespace std;

void main()
{
	NumberList lista;
	lista.Init();
	lista.Add(3);
	lista.Add(6);
	lista.Add(4);
	lista.Add(1);
	lista.Add(9);
	lista.Add(7);
	lista.Print();
	lista.Sort();
	lista.Print();

}