#include <iostream>
#include <ctime>
#include "soldier.h"
#include <string>

void clear_console_buffer()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

// make a temp variable, copy first variable into it, then 
// copy second variable over first variable, then copy temp
// (which stored the first variable) over the second variable
void swap(soldier &a_first_variable, soldier &a_second_variable)
{
	soldier temp = a_first_variable;
	a_first_variable = a_second_variable;
	a_second_variable = temp;
	//temp.overwrite_with( a_first_variable );
	//a_first_variable.overwrite_with( a_second_variable );
	//a_second_variable.overwrite_with( temp );
}

// check if member of an a_team has more health, refer to swap if true
int bubble_sort(soldier a_team[], int a_team_size) 
{
	int index_one, index_two, index_three;
	bool swapped = true;
	while (swapped) 
	{
		swapped = false;
		for (index_one = 0; index_one < a_team_size - 1; ++index_one)
		{
			if (a_team[index_one].get_health() > a_team[index_one + 1].get_health())
			{
				swap(a_team[index_one], a_team[index_one + 1]);
				swapped = true;
			}
		}
	}
	/*for (index_three = 0; index_three < a_team_size; ++index_three)
	{
		if (a_team[index_three].get_health() == 0)
		{
			return index_three - 1;
		}
	}*/
	return a_team_size;
}

// declaring fight function
void fight(soldier a_team_one[], soldier a_team_two[], int a_team_size);

int main() 
{
	// RNGesus graces the program with His glorious presence
	srand(time(0));

	// no heathen magic numbers in the presence of RNGesus
	const int squad_size = 5;
	// to store user-input for entering names for soldiers
	std::string name_buffer;

	// makin' two arrays of soldiers, calling them soldier_squad
	soldier soldier_squad_a[squad_size];
	soldier soldier_squad_b[squad_size];

	// needlessly large game loop that definitely needs a lot of clean-up
	for ( int index = 0; index < squad_size; ++index )
	{
		std::cout << "Please enter a name for soldier number " << index << " for team 1\n";
		std::cin >> name_buffer;
		clear_console_buffer();
		soldier_squad_a[index] = soldier(name_buffer);

		std::cout << "Please enter a name for soldier number " << index << " for team 2\n";
		std::cin >> name_buffer;
		clear_console_buffer();
		soldier_squad_b[index] = soldier(name_buffer);
	}

	int round_counter = 0;
	bool more_than_one = true;
	
	// while more_than_one is true, continue to make the two teams fight
	// currently no way to stop this loop
	while (more_than_one)
	{
		fight( soldier_squad_a, soldier_squad_b, squad_size );
		++round_counter;

		std::cout << "Round: " << round_counter << '\n';

		if (bubble_sort(soldier_squad_a, squad_size) == -1)
		{
			more_than_one = false;
			std::cout << "First Squad is vanquished\n";
		}
		else if (bubble_sort(soldier_squad_b, squad_size) == -1)
		{
			more_than_one = false;
			std::cout << "Second Squad is vanquished\n";
		}
	}

	system("pause");

	return 0;
}

void fight(soldier a_team_one[], soldier a_team_two[], int a_team_size)
{
	int target_one = 0;
	int target_two = 0;
	int	is_dead_check_one = 0;
	int is_dead_check_two = 0;

	for (int index = 0; index < a_team_size; ++index)
	{
		// randomly select a number from a_team_size, minus
		// the currently "dead" members of opposing team
		if (bubble_sort(a_team_two, a_team_size) > 0)
		{
			target_one = rand() % bubble_sort(a_team_two, a_team_size);
		}
		else { target_one = 0; }
		
		if (bubble_sort(a_team_one, a_team_size) > 0)
		{
			target_two = rand() % bubble_sort(a_team_one, a_team_size);
		}
		else { target_two = 0; }

		// team one attacks a random target in team two
		a_team_one[index].attack_target(a_team_two[target_one]);
		std::cout << a_team_one[index].get_name() << " attacks " << a_team_two[target_one].get_name() << '\n';
		std::cout << a_team_two[target_one].get_name() << " receives " << a_team_one[index].get_randomized_damage() << " points of damage\n";
		std::cout << a_team_two[target_one].get_name() << " has " << a_team_two[target_one].get_health() << " health left\n";
		// check if health of target is less than or equal to 0, set is_alive to false if true
		if (a_team_two[target_one].get_health() <= 0)
		{
			a_team_two[target_one].set_alive_status(false);
			std::cout << a_team_two[target_one].get_name() << " is dead!\n";
		}
		// team two attacks a random target in team one
		a_team_two[index].attack_target(a_team_one[target_two]);
		std::cout << a_team_two[index].get_name() << " attacks " << a_team_one[target_two].get_name() << '\n';
		std::cout << a_team_one[target_two].get_name() << " receives " << a_team_two[index].get_randomized_damage() << " points of damage\n";
		std::cout << a_team_one[target_two].get_name() << " has " << a_team_one[target_two].get_health() << " health left\n";
		// check if health of target is less than or equal to 0, set is_alive to false if true
		if (a_team_one[target_two].get_health() <= 0)
		{
			a_team_one[target_two].set_alive_status(false);
			std::cout << a_team_one[target_two].get_name() << " is dead!\n";
		}
	}
}