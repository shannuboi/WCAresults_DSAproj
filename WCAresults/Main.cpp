#include "Vector.h"
#include <iostream>

template <class T>
void print(const my::Vector<T>& vec)
{
	for (int i = 0; i < vec.GetLength(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	my::Vector<int> vec;
	std::cout << vec.isEmpty() << std::endl;
	vec.Pushback(1);
	print(vec);
	vec.Pushback(2);
	print(vec);
	vec.Pushback(69);
	print(vec);
	vec.Pushback(4);
	print(vec);
	vec.Pushback(1);
	print(vec);

	my::Vector<int> newVec = vec;
	newVec.Pushback(420);
	print(vec);
	print(newVec);

	my::Vector<int> movedVec = std::move(vec);
	print(vec);
	print(movedVec);
}