#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

Number::Number(const char* value, int base)
{
    this->value = new char[21];
    strcpy(this->value, value);
    if (base >= 2 && base <= 16)
        this->base = base;
}

Number::Number(const Number& objToCopyFrom)
{
    this->value = new char[21];
    strcpy(this->value, objToCopyFrom.value);
    this->base = objToCopyFrom.base;
}

Number::Number(Number&& objToMoveFrom)
{
    this->value = objToMoveFrom.value;
    this->base = objToMoveFrom.base;
    objToMoveFrom.value = nullptr;
    objToMoveFrom.base = 10;
}

Number::~Number()
{
    delete[] this->value;
}

bool operator<(const Number& n1, const Number& n2)
{
    Number a = n1;
    Number b = n2;
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (strcmp(a.value, b.value) < 0)
        return true;
    else
        return false;
}

bool operator>(const Number& n1, const Number& n2)
{
    Number a = n1;
    Number b = n2;
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (strcmp(a.value, b.value) > 0)
        return true;
    else
        return false;
}

bool operator<=(const Number& n1, const Number& n2)
{
    Number a = n1;
    Number b = n2;
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (strcmp(a.value, b.value) <= 0)
        return true;
    else
        return false;
}

bool operator>=(const Number& n1, const Number& n2)
{
    Number a = n1;
    Number b = n2;
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (strcmp(a.value, b.value) >= 0)
        return true;
    else
        return false;
}

bool operator==(const Number& n1, const Number& n2)
{
    Number a = n1;
    Number b = n2;
    a.SwitchBase(10);
    b.SwitchBase(10);
    if (strcmp(a.value, b.value) == 0)
        return true;
    else
        return false;
}

Number operator-(const Number& n1, const Number& n2)
{
    printf("operator-");
    int base;
    Number a = n1;
    Number b = n2;
    if (a.base > b.base)
        base = a.base;
    else
        base = b.base;

    a.SwitchBase(10);
    b.SwitchBase(10);

    int result = atoi(a.value) - atoi(b.value);

    a.SwitchBase(base);

    _itoa(result, a.value, sizeof(a.value));

    return a;
}

Number operator+(const Number& n1, const Number& n2)
{
    printf("operator+");
    int base;
    Number a = n1;
    Number b = n2;
    if (a.base > b.base)
        base = a.base;
    else
        base = b.base;

    a.SwitchBase(10);
    b.SwitchBase(10);

    int result = atoi(a.value) + atoi(b.value);

    a.SwitchBase(base);

    _itoa(result, a.value, sizeof(a.value));

    return a;
}

Number& Number::operator=(Number&& n)
{
    if (this != &n)
    {
        delete[] value;
        value = n.value;
        base = n.base;
        n.value = nullptr;
        n.base = 0;
    }
    return *this;
}

char Number::operator[](int index) const
{
    printf("operator[]");
    if (index >= 0 && index < strlen(this->value))
        return this->value[index];
    else
        return '\0';
}

void Number::operator--()
{
    char* c = this->value;
    int n = strlen(c);

    for (int i = 0; i < n - 1; i++)
        c[i] = c[i + 1];

    c[n - 1] = '\0';
    strncpy(this->value, c, n - 1);
}

void Number::operator--(int index)
{
    char* c = this->value;
    int n = strlen(c);

    c[n - 1] = '\0';
    strncpy(this->value, c, n - 1);
}

int toDecimal(const char* str, int base)
{
    int len = strlen(str);
    int power = 1;
    int num = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] > '9')
            num += (str[i] - 'A' + 10) * power;
        else
            num += (str[i] - '0') * power;
        power = power * base;
    }

    return num;
}

void Number::SwitchBase(int newBase)
{
    int nr = toDecimal(this->value, this->base);
    char result[21] = "";

    int i = 0;
    while (nr > 0) {
        result[i] = (nr % newBase + '0');
        nr /= newBase;
        i++;
    }

    int n = strlen(result);
    i = 0;
    while (i < n / 2) {
        char aux = result[i];
        result[i] = result[n - i - 1];
        result[n - i - 1] = aux;
        i++;
    }

    strcpy(this->value, result);
    this->base = newBase;
}

void Number::Print()
{
    printf("%s\n", this->value);
}

int Number::GetDigitsCount()
{
    return strlen(this->value);
}

int Number::GetBase()
{
    return this->base;
}
