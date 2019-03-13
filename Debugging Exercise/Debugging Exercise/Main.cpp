// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include "Marine.h"
#include "Zergling.h"
#include <crtdbg.h>

using std::vector;
using std::cout;
using std::endl;

bool marineAlive(vector<Marine> squad);
bool zerglingAlive(vector<Zergling> swarm);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	vector<Marine> squad;
	vector<Zergling> swarm;

	int squadSize = 10;
	int swarmSize = 20;

	// Set up the Squad and the Swarm at their initial sizes listed above

	Marine base_marine;
	for (size_t i = 0; i < squadSize; i++)
	{
		squad.push_back(base_marine);
	}

	for (size_t i = 0; i < squadSize; i++)
	{
		Zergling base_zergling;
		swarm.push_back(base_zergling);
	}

	std::cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << std::endl;
	// Attack each other until only one team is left alive
	while (squad.begin()->isAlive() && swarm.begin()->isAlive()) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad)) // if there's at least one marine alive
		{
			for (size_t index = 0; index < squad.size(); index++) // go through the squad
			{
				if (!swarm[0].isAlive() || !squad[index].isAlive())
				{
					break;
				}
				// each marine will attack the first zergling in the swarm
				std::cout << "A marine fires for " << squad[index].get_attack_damage() << " damage. " << std::endl;
				if (swarm.begin()->isAlive())
				{
					squad[index].attack(&swarm[0]);
				}
				if (!swarm[0].isAlive()) // if the zergling dies, it is removed from the swarm
				{
					cout << "The zergling target dies" << endl;
					swarm.erase(swarm.begin());
				}
			}
		}
		if (zerglingAlive(swarm)) // if there's at least one zergling alive
		{
			for (int index = 0; index < swarm.size(); ++index) // loop through zerglings
			{
				if (!squad[0].isAlive() || !swarm[index].isAlive())
				{
					break;
				}

				std::cout << "A zergling attacks for " << swarm[index].get_attack_damage() << " damage." << endl;
				
				if (squad.begin()->isAlive())
				{
					swarm[index].attack(&squad[0]);
				}
				else 
				{
					squad.erase(squad.begin());
					cout << "The marine succumbs to his wounds." << endl;
				}
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;
	} 
	else if (zerglingAlive(swarm))
	{
		cout << "The Zerg win." << endl;
	}

	system("Pause");
}

// Is there a Marine Alive?
bool marineAlive(vector<Marine> squad)
{
	return squad.size() > 0;
}

// Is there a zergling Alive
bool zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size() > 0;
}
