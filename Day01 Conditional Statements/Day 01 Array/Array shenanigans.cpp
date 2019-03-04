#include <iostream>

void main() 
{
	int number[5]{0,0,0,0,0};
	int user_number = 0;

	std::cout << "Please enter a number" << std::endl;
	std::cin >> user_number;
	number[0] = user_number;
	std::cout << "You have entered " << number[0] << std::endl;
	std::cout << "Please enter a second number" << std::endl;
	std::cin >> user_number;
	number[1] = user_number;
	std::cout << "You have entered " << number[1] << std::endl;
	std::cout << "Please enter a third number" << std::endl;
	std::cin >> user_number;
	number[2] = user_number;
	std::cout << "You have entered " << number[2] << std::endl;
	std::cout << "Please enter a fourth number" << std::endl;
	std::cin >> user_number;
	std::cout << "You have entered " << number[3] << std::endl;
	std::cout << "Please enter a fifth number" << std::endl;
	std::cin >> user_number;
	std::cout << "You have entered " << number[4] << std::endl;

	if (number[0] > 0)
	{
		std::cout << number[0] << " is a positive number" << std::endl;
	}
	else if (number[0] < 0)
	{
		std::cout << number[0] << " is a negative number" << std::endl;
	}
	else
	{
		std::cout << number[0] << " is zero" << std::endl;
	}

	if (number[1] > 0)
	{
		std::cout << number[1] << " is a positive number" << std::endl;
	}
	else if (number[1] < 0)
	{
		std::cout << number[1] << " is a negative number" << std::endl;
	}
	else
	{
		std::cout << number[1] << " is zero" << std::endl;
	}

	if (number[2] > 0)
	{
		std::cout << number[2] << " is a positive number" << std::endl;
	}
	else if (number[2] < 0)
	{
		std::cout << number[2] << " is a negative number" << std::endl;
	}
	else
	{
		std::cout << number[2] << " is zero" << std::endl;
	}

	if (number[3] > 0)
	{
		std::cout << number[0] << " is a positive number" << std::endl;
	}
	else if (number[3] < 0)
	{
		std::cout << number[3] << " is a negative number" << std::endl;
	}
	else
	{
		std::cout << number[3] << " is zero" << std::endl;
	}

	if (number[4] > 0)
	{
		std::cout << number[4] << " is a positive number" << std::endl;
	}
	else if (number[4] < 0)
	{
		std::cout << number[4] << " is a negative number" << std::endl;
	}
	else
	{
		std::cout << number[4] << " is zero" << std::endl;
	}

	std::cin.get();
	system("pause");
}