#include "Hashmap.h"
#include <iostream>

int main()
{
	my::Hashmap<int, std::string> mymap(10);
	mymap.Insert(1, "one");
	mymap.Insert(2, "two");
	mymap.Insert(7, "seven");
	std::cout << mymap.Insert(4, "four") << mymap.Insert(1, "lol") << std::endl;

	for (int i = 0; i < 10; i++)
	{
		auto val = mymap.Search(i);
		if (val.second)
			std::cout << val.first << std::endl;
		else
			std::cout << "NOPE" << std::endl;
	}
}