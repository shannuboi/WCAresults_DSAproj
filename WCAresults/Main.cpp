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
	t.Insert(-3);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(-4);
	t.printInOrder(t.begin()); std::cout << std::endl;
	t.Insert(-6);
	t.printInOrder(t.begin()); std::cout << std::endl;

	my::AVLtree<int> tcopy = t;
	tcopy.Insert(9);
	t.Insert(2);
	tcopy.printInOrder(tcopy.begin()); std::cout << std::endl;
	t.printInOrder(t.begin()); std::cout << std::endl;

	my::AVLtree<int> tmove = std::move(t);
	t.printInOrder(t.begin()); std::cout << std::endl;
	tmove.printInOrder(tmove.begin()); std::cout << std::endl;

}