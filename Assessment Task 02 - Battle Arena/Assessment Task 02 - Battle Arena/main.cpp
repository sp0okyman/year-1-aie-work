#include <iostream>
#include <ctime>
#include "soldier.h"
#include <string>

void clear_console_buffer()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

void fight(soldier a_team_one[], soldier a_team_two[], int a_team_size);

int main() 
{
	srand(time(0));

	const int squad_size = 5;
	std::string name_buffer;

	soldier soldier_squad_a[squad_size];
	soldier soldier_squad_b[squad_size];

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
	
	while (more_than_one)
	{
		fight( soldier_squad_a, soldier_squad_b, squad_size );
		++round_counter;

		std::cout << "Round: " << round_counter << '\n';
	}

	system("pause");

	return 0;
}

void fight(soldier a_team_one[], soldier a_team_two[], int a_team_size)
{
	int target_one = 0;
	int target_two = 0;

	for (int index = 0; index < a_team_size; ++index)
	{
		target_one = rand() % a_team_size;
		target_two = rand() % a_team_size;

		// team one attacks a random target in team two
		a_team_one[index].attack_target(a_team_two[target_one]);
		std::cout << a_team_one[index].get_name() << " attacks " << target_one << '\n';
		std::cout << target_one << " receives " << a_team_one[index].get_attack_value() << " points of damage";
		// check if health of target is less than or equal to 0, set is_alive to false if true
		if (a_team_two[target_one].get_health() <= 0)
		{
			a_team_two[target_one].set_alive_status(false);
			std::cout << a_team_two[target_one].get_name() << " is dead!\n";
		}
		// team two attacks a random target in team one
		a_team_two[index].attack_target(a_team_one[target_two]);
		std::cout << a_team_two[index].get_name() << " attacks " << a_team_one[target_two].get_name() << '\n';
		std::cout << a_team_one[target_two].get_name() << " receives " << a_team_two[index].get_attack_value() << " points of damage";
		// check if health of target is less than or equal to 0, set is_alive to false if true
		if (a_team_one[target_two].get_health() <= 0)
		{
			a_team_one[target_two].set_alive_status(false);
			std::cout << a_team_one[target_two].get_name() << " is dead!\n";
		}
	}
}