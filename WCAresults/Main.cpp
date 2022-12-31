#include "AVLtree.h"

int main()
{
	my::AVLtree<int> t;
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(2);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(3);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(4);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(6);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(1);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(0);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(-1);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(-2);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(7);
	t.printInOrder(t.begin()); std::cout << std::endl;
}