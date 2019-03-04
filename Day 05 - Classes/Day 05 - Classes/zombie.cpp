#include "zombie.h"
#include <string>
#include <iostream>
#include <ctime>

const int enum_length = 3;

// Automatically called on instantiation.
zombie::zombie()
{
	m_health = rand() % 5 + 1;
	m_attack = rand() % 3 + 1;
	m_occupation = (occupation)(rand() % enum_length);
	
	std::cout << "Constructor called" << '\n';
}

// User Constructor.
zombie::zombie(int a_health, int a_attack, occupation a_occupation)
{
	m_health = a_health;
	m_attack = a_attack;
	m_occupation = a_occupation;

	std::cout << "User Constructor called" << '\n';
}

// Automatically called when object is out of scope.
zombie::~zombie()
{
	std::cout << "Destructor called" << '\n';
}

// If copy paste
//1. remove semicolon
//2. scope function
//3. { }
void zombie::to_console() const
{
	std::cout << get_health() << std::endl;
	std::cout << get_attack_value() << std::endl;
	std::cout << get_occupation() << std::endl;
}

// Returns a read only copy of the current health
// without changing the zombie.
const int zombie::get_health() const
{
	return m_health;
}

const int zombie::get_attack_value() const
{
	return m_attack;
}

zombie::occupation zombie::get_occupation() const
{
	return m_occupation; // A const protected copy of a string.
}

void zombie::set_health(int a_health)
{
	m_health = a_health;
}

void zombie::set_attack_value(int a_attack_value)
{
	m_attack = a_attack_value;
}

void zombie::take_damage(const int a_damage)
{
	m_health -= a_damage;
	if (m_health < 0)
	{
		m_health = 0;
	}
}

void zombie::attack(zombie& a_zombie) const
{
	a_zombie.take_damage(m_attack);
}
