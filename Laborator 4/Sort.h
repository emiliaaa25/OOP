#pragma once
class Sort

{
private:
    int* v;
    int count;

public:

    Sort(int n, int min, int max);
    Sort(int v, int count);
    Sort();

    Sort(int number, ...);
    Sort(const char* string);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);


    void QuickSort(int st, int dr, bool ascendent);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};