#include <iostream>
#include <ctime>
// Question 1. What is the output of this program?
//void PrintInteger(int variable)
//{
//	std::cout << variable << std::endl;
//}



// Clears user input so it doesn't clutter later user inputs.
//void ignore_buffer()
//{
//	std::cin.clear();
//	std::cin.ignore(std::cin.rdbuf()->in_avail());
//}

// Question 2 & 3.
//  float user_input_a = 0.0f;
//  float user_input_b = 0.0f;
//  float user_input_c = 0.0f;

//enum coin_state
//{
//	heads,
//	tails,
//	none
//};
//
//coin_state coin_toss();
//
//coin_state coin_toss()
//{
//	int result = rand() % 2;    //0 - RAND_MAX ~ 32000
//	                            // 1-6 I would % 6. 0 - 5
//	switch (result)
//	{
//	case(0):
//		return heads;
//		break;
//	case(1):
//		return tails;
//		break;
//	default:
//		return none;
//		break;
//	}
//
//	return none;
//}



//float smallest_float_returner(float user_input_a, float user_input_b)
//{
//	if (user_input_a > user_input_b)
//	{
//		std::cout << user_input_b << " is the smallest number." << std::endl;
//		return user_input_b;
//	}
//	else
//	{
//		std::cout << user_input_a << " is the smallest number." << std::endl;
//		return user_input_a;
//	}
//}



// Question 3.

//float smallest_float_returner(float user_input_a, float user_input_b, float user_input_c)
//{
//	if (user_input_a < user_input_b) {
//		if (user_input_a < user_input_c)
//		{
//			std::cout << user_input_a << " is the smallest number." << std::endl;
//			return user_input_a;
//		}
//	}
//	else if (user_input_b < user_input_a)
//	{
//		if (user_input_b < user_input_c)
//		{
//			std::cout << user_input_b << " is the smallest number." << std::endl;
//			return user_input_b;
//		}
//	}
//	else if (user_input_c < user_input_a)
//	{
//		if (user_input_c < user_input_b)
//		{
//			std::cout << user_input_c << " is the smallest number." << std::endl;
//			return user_input_c;
//		}
//	}
//}

// Question 4.
//	float half(float number)
//{
//	float number_halfed = number / 2.0f;
//	return number_halfed;
//}

// Question 6. There's a problem with these two functions, find it and make a fix

//int sum(int x, int y)
//{
//	int result;
	// doesn't return a value.
//	result = x + y;
	// return result; FIX
//}

//int sum(int n)
//{
//	if (0 == n)
//		return 0;
//	else n = n + n;
//	return n; FIX
//}

//int main()
//{
//	double x = 13.6;
//	std::cout << "sqaure of 13.6 = " << square(x) << std::endl;
//}
//	FUNCTION IS BELOW MAIN() FIX IS TO MOVE IT ABOVE MAIN()
//int square(int x)
//{
//	return x * x;
//}
	

int main() 
{

	// Question 1. What is the output of this program?
		// Prints to console: 1, 1, 2, 2, 3, 2, 1

	//	int the_variable = 1;
	//	PrintInteger(the_variable);
	//	{
	//		PrintInteger(the_variable);
	//		int the_variable = 2;
	//		PrintInteger(the_variable);
	//		{
	//			PrintInteger(the_variable);
	//			int the_variable = 3;
	//			PrintInteger(the_variable);
	//		}
	//		PrintInteger(the_variable);
	//	}
	//	PrintInteger(the_variable);
	


	// Question 2 & 3. Write a function that returns the smaller of two floats that are passed to it:
	//You should make a program that asks the user for two different numbers such that it outputs:
	// Enter value 1: 10.6
	//Pass the two numbers into a function and output what the function returns:
	// The smaller number is: -67.8

//	std::cout << "Please enter a floating number" << std::endl;
//	std::cin >> user_input_a;
//	ignore_buffer();
//	std::cout << "Please enter another floating number" << std::endl;
//	std::cin >> user_input_b;
//	ignore_buffer();
//	std::cout << "Please enter yet another floating number" << std::endl;
//	std::cin >> user_input_c;
//	ignore_buffer();
//	smallest_float_returner(user_input_a, user_input_b, user_input_c);



	// Question 4.
//	float number = 16.721f;
//	std::cout << number << '\n';
//	float result = half(number);
//	std::cout << result << '\n';
	


	// Question 5.
	//	srand(time(0)); // Enables 'better' random.
	//
	//	int head_count = 0;
	//	int tails_count = 0;
	//
	//	std::cout << "How many times would you like to flip the coin?\n";
	//	int flips = 0;
	//	std::cin >> flips;
	//	
	//	for (int flip_count = 0; flip_count < flips; ++flip_count)
	//	{
	//		coin_state current_state = coin_toss();
	//		switch (current_state)
	//		{	
	//		case(0):
	//			std::cout << "Heads\n";
	//			++head_count;
	//			break;
	//		case(1):
	//			std::cout << "Tails\n";
	//			++tails_count;
	//			break;
	//		default:
	//			std::cout << "Invalid coin state found.\n";
	//			break;	
	//		}
	//	}
	//
	//	std::cout << head_count << '\n';
	//	std::cout << tails_count << '\n';

	system("Pause");
}