#include <iostream>

// declaring function
int binary_search(int a_array[], int a_left, int a_right, int a_turns);

int main()
{
	char user_input;
	bool guess_correct;

	const int array_size = 100;
	int possible_guesses[array_size];

	for (int index = 0; index < 100; ++index)
	{
		possible_guesses[index] = index + 1;
	}

	binary_search(possible_guesses, 0, array_size, 0);

	system("pause");

	return 0;
}

// defining binary_search
int binary_search(int a_array[], int a_left, int a_right, int a_turns)
{
	int mid = a_left + (a_right - a_left) / 2;
	char user_input;

	std::cout << "Is your number greater than, less than or equal to " << mid << std::endl;
	std::cin >> user_input;

	if (a_right >= a_left)
	{
		switch (user_input) 
		{
		case '=':
			std::cout << "Your number was " << mid << std::endl;
			std::cout << "Turns taken = " << a_turns + 1 << std::endl;
			return mid;
			break;
		case '>':
			++a_turns;
			return binary_search(a_array, a_left, mid - 1, a_turns);
			break;

		case '<':
			++a_turns;
				return binary_search(a_array, mid + 1, a_right, a_turns);
				break;
		default:
			std::cout << "That is not a valid input, input the symbols '>', '<' or '=' to represent your answer." << std::endl;
			return binary_search(a_array, a_left, a_right, a_turns);
			break;
		}
	}
	return -1;
}