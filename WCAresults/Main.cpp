#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> myLL;

	myLL.PushFront(10);
	myLL.PushFront(22);
	myLL.PushFront(43);
	myLL.PushFront(7);

	for (auto Iter = myLL.begin(); Iter != myLL.end();)
	{
		std::cout << *Iter << " ";
		if (*Iter < 10)
		{
			*Iter = 69;
		}
		else
		{
			Iter++;
		}
	}
}