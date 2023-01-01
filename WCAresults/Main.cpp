#include "Program.h"
#include <iostream>

int main()
{
	my::Array<int> lol(5);
	lol[0] = 10;
	lol[1] = 110;
	lol[2] = 100;
	lol[3] = 60;
	lol[4] = 0;

	for (auto e : lol)
	{
		std::cout << e << " ";
	}
}