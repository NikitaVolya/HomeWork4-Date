
#include <iostream>

#include "Date.h"

int main()
{
	Date a(13, 3, 2006);
	Date b(16, 4, 2024);

	a += 20;
	b -= 154;

	a.print();
	b.print();

	std::cout << b.differenceInDays(a);
}