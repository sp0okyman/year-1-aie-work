#include "soldier.h"
#include <iostream>
#include <ctime>
#include <string>

const int enum_length = 3;

// Automatically called on instantiation.
soldier::soldier()
{
	m_health = rand() % 15 + 1;
	m_attack = rand() % 3 + 1;
	m_specialization = (specialization)(rand() % enum_length);
	m_if_alive = true;
}


soldier::soldier(std::string a_name)
{
	m_health = rand() % 15 + 1;
	m_attack = rand() % 3 + 1;
	m_specialization = (specialization)(rand() % enum_length);
	m_name = a_name;
}

// Automatically called when object is out of scope.
soldier::~soldier(){}

const int soldier::get_health() const
{
	return m_health;
}

const int soldier::get_attack_value() const
{
	return m_attack;
}

const bool soldier::get_alive_status() const
{
	return m_if_alive;
}

const std::string soldier::get_name() const
{
	return m_name;
}

soldier::specialization soldier::get_specialization() const
{
	return m_specialization;
}

void soldier::set_health(int a_health)
{
	m_health = a_health;
}

void soldier::set_attack_value(int a_attack_value)
{
	m_attack = a_attack_value;
}

void soldier::set_name(std::string a_name)
{
	m_name = a_name;
}

void soldier::set_alive_status(bool a_alive_status)
{
	m_if_alive = a_alive_status;
}

void soldier::take_damage(const int a_damage)
{
	m_health -= a_damage;
	if ( m_health < 0 ) { m_health = 0; }
}

void soldier::attack(soldier& a_squad) const { a_squad.take_damage(m_attack); }

void soldier::attack_target(soldier& a_target)
{
	a_target.take_damage(m_attack);
}