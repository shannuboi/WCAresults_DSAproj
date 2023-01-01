#include "AVLtree.h"
#include <iostream>

int main()
{
	auto printer = [](int val) {
		std::cout << "|" << val << "|";
	};
	my::AVLtree<int> t;
	my::InOrderTriversal(t.begin(), t.end(), printer); std::cout << std::endl;
	t.Insert(50);
	my::InOrderTriversal(t.begin(), t.end(), printer); std::cout << std::endl;
	t.Insert(51);
	my::InOrderTriversal(t.begin(), t.end(), printer); std::cout << std::endl;
	t.Insert(52);
	my::InOrderTriversal(t.begin(), t.end(), printer); std::cout << std::endl;
}