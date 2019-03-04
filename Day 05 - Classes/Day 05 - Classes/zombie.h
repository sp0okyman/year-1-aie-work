#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
// Class declaration
class zombie
{
	enum occupation { Virgin, Chad, Stacy };
public:

	// (Default) Constructor (Because no arguments)
	zombie();

	// User Constructor.
	zombie(int a_health, int a_attack, occupation a_occupation);


	// Destructor
	~zombie();

	// Member Function
	// Writes member data to console
	void to_console() const;

	/**Accessors**/
	// const int - don't alter the return value
	// () const - function doesn't change the object
	const int get_health() const;
	const int get_attack_value() const;
	occupation get_occupation() const;

	/* Setters */
	void set_health(int a_health);
		void set_attack_value(int a_attack_value);
		void attack(zombie& a_zombie) const;


private: 
	// whole number of remaining hitpoints.
	int m_health = 0;

	// whole number of damage dealt per attack.
	int m_attack = 0;

	// previous job description.
	occupation m_occupation;

	void take_damage(const int a_damage);
};
#endif // !ZOMBIE_H
