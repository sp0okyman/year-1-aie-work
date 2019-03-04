#include <iostream>

// creating function to check for the win conditions
bool win_condition_met(int** a_array, int a_array_length)
{
	bool is_win = false;

	// win condition check for row
	for (int row = 0; row < a_array_length; ++row)
	{
		// compares first and second variables, if true, then checks the second and third variable if they're the same,
		// if true, checks the first variable is not a zero
		if (a_array[row][0] == a_array[row][1] && a_array[row][1] == a_array[row][2] && a_array[row][0] != 0)
		{ is_win = true; }
	}

	// win condition check for column
	for (int column = 0; column < a_array_length; ++column)
	{
		// yadda yadda same shit from above
		if (a_array[0][column] == a_array[1][column] && a_array[1][column] == a_array[2][column] && a_array[0][column] != 0)
		{ is_win = true; }
	}

	// win condition check for right diagonal
	if (a_array[0][0] == a_array[1][1] && a_array[1][1] == a_array[2][2] && a_array[0][0] != 0)
	{is_win = true;}
	
	// win condition check for left diagonal
	if (a_array[0][2] == a_array[1][1] && a_array[1][1] == a_array[2][0] && a_array[0][2] != 0)
	{ is_win = true; }

	if (is_win)
	{
		return true;
	}
	else { return false; }
}

bool board_full_check(int** a_array, int a_array_length)
{
	for (int row = 0; row < a_array_length; ++row)
	{
		for (int column = 0; column < a_array_length; ++column)
		{
			if (a_array[row][column] != 1 || a_array[row][column] != 2)
				return false;
		}
	}
	return true;
}

// creating function to display the tic tac toe board and its current state
void print_board(int** a_array, int a_array_length)
{
	for (int row = 0; row < a_array_length; ++row)
	{
		for (int column = 0; column < a_array_length; ++column)
		{
			switch (a_array[row][column])
			{
			case 1: std::cout << "X ";
				break;
			case 2: std::cout << "O ";
				break;
			default:std::cout << "_ ";
				break;
			}
		}

		std::cout << "\n";
	}
}

int main()
{	// constant(static) integer to represent the length of the board (the array).
	const int array_length = 3;
	// pointer to board array
	int** pointer_board = new int*[array_length];

	// creating the tic tac toe board array
	for (int index = 0; index < array_length; index++)
	{
		pointer_board[index] = new int[array_length] {0};
	}

	print_board(pointer_board, array_length);

	int player_input = 0;
	int board_input_row = 0;
	int board_input_column = 0;

	while (board_full_check(pointer_board, array_length) == false)
	{
		while (true)
		{
			std::cout << "Please enter 1 or 2 for X or O, respectively.\n";
			std::cin >> player_input;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			if (player_input == 1 || player_input == 2)
			{
				break;
			}
		}
		while (true)
		{
			std::cout << "Please enter the number of the row you wish to enter\n";
			std::cin >> board_input_row;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			if (player_input == 0 || player_input == 1 || player_input == 2)
			{
				break;
			}
		}

		while (true)
		{
			std::cout << "Please enter the number of the column you wish to enter\n";
			std::cin >> board_input_column;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			if (player_input == 0 || player_input == 1 || player_input == 2)
			{
				break;
			}
		}

		system("cls");
		if (board_input_row < array_length && board_input_column < array_length)
		{
			pointer_board[board_input_row][board_input_column] = player_input;
		}

		print_board(pointer_board, array_length);

		if (win_condition_met(pointer_board, array_length) == true)
		{
			break;
		}
	}

	std::cout << "The brainlet test is over.\n";
	std::cout << "Player " << player_input << " has won. Cheeky bastard.\n";

	system("pause");

	delete[] pointer_board;
	pointer_board = nullptr;


	return 0;
}