#include <iostream>
#include <ctime>

void main()
{
	 // This is a valid definition, as the array holds 10 total integers, and there are 10 individual integer values	   
//	   int numbers[10] = { 0, 0, 1, 0. 0, 1, 0, 0, 1, 1 };
	 // This is an invalid definition, as the array can only hold 5 total integers, but it is holding 7 of them. This will cause buffer overflow
//	   int matrix[5] = { 1, 2, 3, 4, 5, 6, 7 };
	 // This is a valid definition, as the array can hold up to 10 total doubles, and while there are only 2 declared doubles, the rest are automatically assumed to be 0
//	   double radii[10] = (3.2, 4.7];
	 // This is an invalid definition, as the array can hold up to 7 total integers, but 3 values are not declared, while occupying the index of the array
//	   int table[7] = { 2, , , 27, , 45, 39 };
	 // This is a valid definition, as though the array has no defined maximum space, it is assmed that it is 5 because 5 values are being held in it
//	   char codes[] = { 'A', 'X', '1', '2', 's' };
	 // This is an invalid definition, since the array holds asbolutely nothing, and has no defined space
//	   int blanks[];
	 // This is an invalid definition, since arrays cannot hold negative space
//	   int collection[-20];
	 // This is an invalid definition, since there are no braces
//	   int hours[3] = 8, 12, 16;


//	int values[] = { 2, 6, 10, 14 };
	// This will show 10
//	std::cout << values[2] << '\n';
	// This will show 3
//	std::cout << ++values[0] << '\n';
	// This will show 6, but increment it thereafter to be 7
//	std::cout << values[1]++ << '\n';
	// This will show 14, since it will increment from position 2 in the array to 3
//	int x = 2;
//	std::cout << values[++x] << '\n';
	// This will show a very, very bad number
//	std::cout << values[4] << '\n';


	// Question 3
//	const int datalength = 10;
//	int data[datalength];
//	
//	for (int pos = datalength-1; pos >= 0; --pos)
//	{
//		data[pos] = datalength - pos;
//
//		std::cout << data[pos] << '\n';
//	}

	// Question 4
//	const int input_count = 5;
//	int user_input[input_count];
//	std::cout << "Please enter 5 numbers." << '\n';
//	for (int index = 0; index < input_count; ++index)
//	{
//		std::cin >> user_input[index];
//	}
//
//	for (int index = input_count - 1; index >= 0; --index)
//	{
//		std::cout << user_input[index] << '\n';
//	}

	// Question 5. Write a program that lets the user enter 10 values into an array.
	// The program should then display the largest and smallest values stored in the array.
//	const int large_input_count = 10;
//	int large_user_input[large_input_count];
//
//	std::cout << "Please enter 10 numbers." << '\n';
//
//	int largest_number = INT_MIN;
//	int smallest_number = INT_MAX;
//	for (int index = 0; index < large_input_count; ++index)
//	{
//		std::cin >> large_user_input[index];
//		if (largest_number < large_user_input[large_input_count])
//		{
//			largest_number = large_user_input[index];
//		}
//	}
//	for (int index = 0; index < large_input_count; ++index)
//	{
//		std::cin >> large_user_input[index];
//	}
//
//	for (int index = large_input_count - 1; index >= 0; --index)
//	{
//		std::cout << large_user_input[index] << '\n';
//	}

	// Question 6.

//	// defining size of array
//	const int height = 3;
//	const int width = 3;
//
//	// keeping track of location on array
//	int count = 0;
//	int sum = 0;
//
//	// my array
//	int lad[height][width];
//
//	// loop to fill array with shit
//	for (int y = 0; y < height; ++y)
//	{
//		for (int x = 0; x < width; ++x)
//		{
//			++count;
//			lad[y][x] = count;
//			std::cout << "[" << y << "][" << x << "] = " << lad[y][x] << " ";
//			sum += count;
//		}
//		std::cout << sum << '\n';
//	}

	// Question 7.

//	srand(time(0));
//	const int days = 29;
//	const int months = 5;
//	int date[months][days];
//	// Randomizing values in array in a range of 1 to 9
//	for (int month_index = 0; month_index < months; ++month_index)
//	{
//		for (int days_index = 0; days_index < days; ++days_index)
//		{								// Modulo max plus min
//			date[month_index][days_index] = rand() % 9 + 1;
//		}
//	}
//	// Sum of the ROWS
//	int sum = 0;
//	for (int month_index = 0; month_index < months; ++month_index)
//	{
//		for (int days_index = 0; days_index < days; ++days_index)
//		{
//			sum += date[month_index][days_index];
//		}
//		std::cout << "Rows: " << sum << '\n';
//		sum = 0;
//	}
//	// Sum of the COLUMNS
//	sum = 0;
//	for (int days_index = 0; days_index < days; ++days_index)
//	{
//		for (int month_index = 0; month_index < months; ++month_index)
//		{
//			sum += date[month_index][days_index];
//		}
//		std::cout << "Columns: " << sum << '\n';
//		sum = 0;
//	}

	// Question 8.

	int character_health[5]{100, 100, 100, 100, 100};
	int damage = -40;
	int user_input = 0;
	const int input_max = 4;
	int attacks = 5;

	for (int index = 0; index < attacks; ++index)
	{
		std::cout << "Please enter a number from 0 to 4" << '\n';
		std::cin >> user_input;

		if (user_input <= input_max)
		{
			character_health[user_input] += damage;
		}
		else
		{
			std::cout << "Please enter a number from 0 to 4, you previously entered a number greater than 4\n";
			--index;
		}

		if (character_health[user_input] <= 0 && user_input <= input_max)
		{
			std::cout << "Character " << user_input << " is dead\n";
		}

		// Question 9.
		
		const int dragons = 3;
		const int days = 7;
		float food_kilos = 0.0f;

		int dragon_array[dragons][days];


	}
	system("Pause");

}