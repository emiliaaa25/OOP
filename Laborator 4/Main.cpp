#include <iostream>
#include <cstring>
#include "Sort.h"
char input[] = "5, 1, 4, 2, 8";
int main() {

	Sort s(input);

	std::cout << "Sortare crescatoare: ";
	s.BubbleSort(true);
	s.Print();

	std::cout << "Sortare descrescatoare: ";
	s.QuickSort(true);
	s.Print();

	std::cout << s.GetElementsCount();
	std::cout << s.GetElementFromIndex(4);

	return 0;
}