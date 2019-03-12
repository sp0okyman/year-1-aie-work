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
//void swap(soldier* a_first_variable, soldier* a_second_variable)
//{
//	soldier* temp = a_first_variable;
//	a_first_variable = a_second_variable;
//	a_second_variable = temp;
//	temp.overwrite_with( a_first_variable );
//	a_first_variable.overwrite_with( a_second_variable );
//	a_second_variable.overwrite_with( temp );
//}

// check if member of an a_team has more health, refer to swap if true
int bubble_sort(soldier* a_team[], int a_team_size) 
{
	bool swapped = true;
	while (swapped) 
	{
		swapped = false;
		for (int index = 0; index < a_team_size - 1; ++index)
		{
			if (a_team[index]->get_health() < a_team[index + 1]->get_health())
			{
				soldier* temp = a_team[index];
				a_team[index] = a_team[index + 1];
				a_team[index + 1] = temp;

				swapped = true;
			}
		}
	}
	for (int index = 0; index < a_team_size; ++index)
	{
		if (a_team[index]->get_health() == 0)
		{
			return index - 1;
		}
	}
	return a_team_size;
}

// declaring fight function
void fight(soldier* a_team_one[], soldier* a_team_two[], int a_team_size);
// declaring attacker function
void attacking(soldier* a_attacker, soldier* a_target, int a_team_size);

int main() 
{
	// RNGesus graces the program with His glorious presence
	srand(time(0));

	// no heathen magic numbers in the presence of RNGesus
	const int squad_size = 2;
	// to store user-input for entering names for soldiers
	std::string name_buffer;

	// makin' two arrays of soldiers, calling them soldier_squad
	soldier* soldier_squad_a[squad_size];
	soldier* soldier_squad_b[squad_size];

	// needlessly large game loop that definitely needs a lot of clean-up
	for ( int index = 0; index < squad_size; ++index )
	{
		std::cout << "Please enter a name for soldier number " << index << " for team 1\n";
		std::cin >> name_buffer;
		clear_console_buffer();
		soldier_squad_a[index] = new soldier(name_buffer);

		std::cout << "Please enter a name for soldier number " << index << " for team 2\n";
		std::cin >> name_buffer;
		clear_console_buffer();
		soldier_squad_b[index] = new soldier(name_buffer);
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
			std::cout << "First Squad has been defeated\n";
		}
		else if (bubble_sort(soldier_squad_b, squad_size) == -1)
		{
			more_than_one = false;
			std::cout << "Second Squad has been defeated\n";
		}
	}

	system("pause");

	return 0;
}

// defining fight function
void fight(soldier* a_team_one[], soldier* a_team_two[], int a_team_size)
{
	int target_one = 0;
	int target_two = 0;
	int	is_dead_check_one = 0;
	int is_dead_check_two = 0;

	for (int index = 0; index < a_team_size; ++index)
	{
		int team_one_survivor_count = bubble_sort(a_team_one, a_team_size);
		int team_two_survivor_count = bubble_sort(a_team_two, a_team_size);

		// randomly select a number from a_team_size, minus
		// the currently "dead" members of opposing team

		if (team_one_survivor_count > 0)
		{
			target_one = rand() % team_two_survivor_count;
		}
		else { target_one = 0; }

		if (team_two_survivor_count > 0)
		{
			target_two = rand() % team_one_survivor_count;
		}
		else { target_two = 0; }
		
		attacking(a_team_one[index], a_team_two[target_one], a_team_size);
		attacking(a_team_two[index], a_team_one[target_two], a_team_size);

		team_one_survivor_count = bubble_sort(a_team_one, a_team_size);
		team_two_survivor_count = bubble_sort(a_team_two, a_team_size);

		// Win condition check...
		if (team_one_survivor_count == -1)
		{
			return;
		}

		if (team_two_survivor_count == -1)
		{
			return;
		}

	}
}

void attacking(soldier* a_attacker, soldier* a_target, int a_team_size)
{
	if (a_attacker->get_alive_status() == true)
	{
		a_attacker->attack_target(*a_target);
		// team two attacks a random target in team one
		std::cout << a_attacker->get_name() << " attacks " << a_target->get_name() << '\n';
		std::cout << a_target->get_name() << " receives " << a_target->get_randomized_damage() << " points of damage\n";
		std::cout << a_target->get_name() << " has " << a_target->get_health() << " health left\n";
		// check if health of target is less than or equal to 0, set alive_status to false if true
		if (a_target->get_health() <= 0)
		{
			a_target->set_alive_status(false);
			std::cout << a_target->get_name() << " is dead!\n";
		}
	}
}