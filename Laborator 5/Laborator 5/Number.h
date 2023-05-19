#pragma once
class Number
{


public:

	char* value;
	int base;



	Number(const char* value, int base = 10); // where base is between 2 and 16

	Number(const Number& objToCopyFrom);

	Number(Number&& objToMoveFrom);

	~Number();


	friend bool operator<(Number n1, Number n2);

	friend bool operator>(Number n1, Number n2);

	friend bool operator<=(Number n1, Number n2);

	friend bool operator>=(Number n1, Number n2);

	friend bool operator==(Number n1, Number n2);

	friend Number operator-(Number n1, Number n2);

	friend Number operator+(Number n1, Number n2);

	Number& operator = (Number&& n);

	char operator[](int index) const;

	void operator--();

	void operator--(int index) ;

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount();

	int  GetBase();
};

