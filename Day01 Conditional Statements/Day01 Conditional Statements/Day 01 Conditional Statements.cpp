#include <iostream>

void main()
{
	int x = 0;
	int y = 0;
	//
	//if (y == 0) 
	//{
	//	x = 100;
	//}

	std::cout << "Please enter a number" << std::endl;
	std::cin >> x;
	std::cout << "You have entered " << x << std::endl;
	std::cout << "Please enter a second number" << std::endl;
	std::cin >> y;
	std::cout << "You have entered " << y << std::endl;

	if (x > y) {
		std::cout << x << " is the larger number" << std::endl;
	}
	else {
		std::cout << y << " is the larger number" << std::endl;
	}



	std::cout << x;
	std::cin.get();
	std::cin.get();
}