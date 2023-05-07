#include"mapa.h"
#include<iostream>
#include<stdio.h>
using namespace std;
int main()

{

    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";
   
  
    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }
    
    m[20] = "result";

    for (auto [key, value, index] : m)

    {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);

    }
    
    cout << "Set:" << endl;
    m.Set(7,"da");
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "Delete:" << endl;
    m.Delete(30);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "Get:" << endl;
    const char* acum;
    m.Get(10, acum);
    cout << acum<<endl;

    cout << m.Count() << endl;

    cout << "Clear" << endl;
    m.Clear();
  

    return 0;

}