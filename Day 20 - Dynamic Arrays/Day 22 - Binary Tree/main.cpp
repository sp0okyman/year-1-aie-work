#include "binary_tree.h"
#include <iostream>

int main()
{
	binary_tree<int> bt;
	bt.insert(10);
	bt.insert(6);
	bt.insert(15);
	bt.insert(14);
	bt.insert(5);

	bt.find(5);

	std::cout << bt.find(5) << '\n';

	system("pause");

	return 0;
}