#include <iostream>

void guess();
void user_inquiry();

int main()
{
	char user_input;
	

	guess();
	user_inquiry();

	system("pause");

	return 0;
}

void guess()
{
	const int array_size = 100;
	int possible_guesses[array_size];

	for (int index = 0; index < 100; ++index)
	{
		possible_guesses[index] = index + 1;
	}
}

//void user_inquiry()
//{
//	std::cout << "Is your number greater or less than " <<  << '\n';
//}