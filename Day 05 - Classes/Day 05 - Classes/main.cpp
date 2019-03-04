#include <iostream>
#include "zombie.h"
#include <ctime>

// Question 1. Create a class called zombie.

int main()
{
	srand(time(0));

	zombie zombie_horde[5];

	int round_counter = 0;
	bool more_than_one = true;
	while (more_than_one)
	{
		++round_counter;

		std::cout << "Round: " << round_counter << '\n';

		//battle - 1 random vs 1 random
		int zombA = rand() % 5;
		int zombB = rand() % 5;
		
		zombie_horde[zombA].attack(zombie_horde[zombB]);

		//check - count number of living zombies
		int counter = 0;
		more_than_one = false;
		for (size_t index = 0; index < 5; ++index)
		{
			if (zombie_horde[index].get_health() > 0)
			{
				counter++;
				if (counter >= 2)
				{
					more_than_one = true;
					break;
				}
			}
		}
	}

	system("Pause");
	return 0;
}