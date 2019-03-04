#include "pch.h"
#include <iostream>

using namespace std;

const char* ESC = "\x1b";
const char* CSI = "\x1b[";

const char* TITLE = "x1b[5;20H";
const char* INDENT = "\t";
const char* YELLOW = "\x1b93m";
const char* MAGENTA = "x1b[95m";
const char* RESET_COLOR = "\x1b[0m";
const char* SAVE_CURSOR_POS = "\x1b[s";
const char* RESTORE_CURSOR_POS = "\x1b[u";

void ignore_buffer()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

int main()
{
	const int EMPTY = 0;
	const int ENEMY = 1;
	const int TREASURE = 2;
	const int FOOD = 3;
	const int ENTRANCE = 4;
	const int EXIT = 5;
	const int MAX_RANDOM_TYPE = FOOD + 1;

	const int MAZE_WIDTH = 10;
	const int MAZE_HEIGHT = 6;

	//2d array
	int rooms[MAZE_HEIGHT][MAZE_WIDTH];

	int height = 0;
	int avatar_hp = 0;
	char first_letter_name = 0;

	system("cls");

	std::cout << INDENT << INDENT << "Welcome to ZORP!" << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning." << std::endl;
	std::cout << INDENT << "It is definitely not related to any other text-based adventure game." << std::endl << std::endl;

	std::cout << INDENT << "First, some questions..." << std::endl;
	std::cout << INDENT << "How tall are you, in centimeters? " << INDENT << std::endl;

	std::cin >> height;
	std::cout << std::endl;

	if (std::cin.fail())
	{
		std::cout << INDENT << "You have failed the first challenge and are eaten by a grue." << std::endl;
	}
	else 
	{
		std::cout << INDENT << "You entered " << height << std::endl;
	}
	ignore_buffer();

	std::cout << INDENT << "What is the first letter of your name?" << INDENT << std::endl;

	std::cin >> first_letter_name;
	std::cout << std::endl;

	if (std::cin.fail() || !isalpha(first_letter_name))
	{
		std::cout << INDENT << "You have failed the second challenge and are eatenn by a grue." << std::endl;
	}
	else
	{
		std::cout << INDENT << "You entered " << first_letter_name << std::endl;
	}
	ignore_buffer;

	if (first_letter_name != 0) 
	{
		avatar_hp = (float)height / (first_letter_name * 0.02f);
	}
	else
	{
		avatar_hp = 0;
	}

	std::cout << INDENT << "Using a complex deterministic algorithm, it has been calculated that you have " << avatar_hp << " hit point(s)." << std::endl;

	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program." << std::endl;
	std::cin.get();
	return 0;

}