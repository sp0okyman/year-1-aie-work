#include <iostream>

void main()
{
	int lvl = 1;

	int user_input;

	int str = 0;
	int mag = 0;

	std::cout << "please enter a number for STR" << std::endl;
	std::cin >> str;
	std::cout << "you have entered " << str << std::endl;
	std::cout << "please enter a number for MAG" << std::endl;
	std::cin >> mag;
	std::cout << "you have entered " << mag << std::endl;
	
	int luk = str + mag;

	std::cout << "your LUK is " << luk << std::endl;

	float hitpoints = 100.5f;
	float manapoints = 100.5f;
	float limitgauge = hitpoints + manapoints;

	std::cout << lvl << str << mag << luk << "\n";
	lvl ++;
	str ++;
	mag ++;
	luk = str + mag;
	std::cout << lvl << str << mag << luk << "\n";
	lvl ++;
	str ++;
	mag ++;
	luk = str + mag;
	std::cout << lvl << str << mag << luk << "\n";
	lvl ++;
	str ++;
	mag ++;
	luk = str + mag;
	std::cout << lvl << str << mag << luk << "\n";
	std::cout << limitgauge << "\n";
	
	std::cout << "please enter a number, thanks lad" << std::endl;

	std::cin >> user_input;

	std::cout << "you have entered " << user_input << std::endl;

	std::cin.get(); 
	std::cin.get();
	return;
}