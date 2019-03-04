#include <iostream>

void main()
{
	int multi_one = 3;
	int multi_two = 5;

	for (int number = 0; number <= 100; number++)
	{
		if (number == 0)
		{
			std::cout << number << '\n';
			continue;
		}

		if (number % multi_one == 0 && number % multi_two == 0)
		{
			std::cout << "FizzBuzz" << '\n';
		}
		else if (number % multi_one == 0)
		{
			std::cout << "Fizz" << '\n';
		}
		else if (number % multi_two == 0)
		{
			std::cout << "Buzz" << '\n';
		}
		else
		{
			std::cout << number << '\n';
		}
	}
	// euler problem
	int sum = 0;
	int x = 1000;
	for (int i = 0; i < x; ++i)
	{
		if (i % multi_one == 0 || i % multi_two == 0)
		{
			sum += i;
		}
	}
	std::cout << sum << '\n';
	
	// while loop conversion of for loop above.
//	int number = 0;
//	while(number < 100)
//	{
//		if(number == 0) 
//		{
//			std::cout << number << '\n';
//			number++;
//			continue;
//		}
//
//		if (number % multi_one == 0 && number % multi_two == 0)
//		{
//			std::cout << "FizzBuzz" << '\n';
//		}
//		else if (number % multi_one == 0)
//		{
//			std::cout << "Fizz" << '\n';
//		}
//		else if (number % multi_two == 0)
//		{
//			std::cout << "Buzz" << '\n';
//		}
//		else
//		{
//			std::cout << number << '\n';
//		}
//		++number;
//	}
	
	// euler problem while loop conversion
//	int sum = 0;
//	int x = 1000;
//	int i = 0;
//	while (i < x)
//	{
//		if (i % multi_one == 0 || i % multi_two == 0)
//		{
//			sum += i;
//		}
//		++i;
//	}
//	std::cout << sum << '\n';
	
	system("pause");
}