#include "Canvas.h"

int main()
{
	Canvas c(50, 50);
	c.FillRect(1, 1, 5, 9, '%');
	c.DrawRect(1, 1, 5, 9, '$');
	c.DrawLine(1, 1, 1, 9, '@');
	c.FillCircle(10, 10, 9, '!');
	c.DrawCircle(10, 10, 9, '~');
	c.Print();
	c.Clear();
	c.DrawLine(10, 10, 46, 47, '*');
	c.Print();
}
