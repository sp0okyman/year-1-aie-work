#include "soldier.h"
#include <iostream>
#include <ctime>
#include <string>

const int enum_length = 3;

// Automatically called on instantiation.
soldier::soldier()
{
	m_health = rand() % 20 + 10;
	m_attack = rand() % 5 + 3;
	m_min_attack = m_attack - 1;
	m_max_attack = m_attack + 1;
	m_specialization = (specialization)(rand() % enum_length);
	m_alive_status = true;
	m_name = "";
}

void soldier::overwrite_with(soldier a_soldier)
{
	m_randomized_damage = a_soldier.get_randomized_damage();
	m_min_attack = a_soldier.get_min_attack();
	m_max_attack = a_soldier.get_max_attack();
	m_attack = a_soldier.get_attack_value();
	m_health = a_soldier.get_health();
	m_name = a_soldier.get_name();
}

soldier::soldier(std::string a_name)
{
	m_health = rand() % 20 + 10;
	m_attack = rand() % 5 + 3;
	m_min_attack = m_attack - 1;
	m_max_attack = m_attack + 1;
	m_specialization = (specialization)(rand() % enum_length);
	m_alive_status = true;
	m_name = a_name;
}

// Automatically called when object is out of scope.
soldier::~soldier(){}

// getters
const int soldier::get_health() const{return m_health;}
// get attack values
const int soldier::get_attack_value() const{return m_attack;}
const int soldier::get_min_attack() const{return m_min_attack;}
const int soldier::get_max_attack() const{return m_max_attack;}
const int soldier::get_randomized_damage() const{return m_randomized_damage;}

const bool soldier::get_alive_status() const{return m_alive_status;}
const std::string soldier::get_name() const{return m_name;}
soldier::specialization soldier::get_specialization() const{return m_specialization;}

// setters
void soldier::set_health(int a_health){	m_health = a_health; }
// set attack values
void soldier::set_attack_value(int a_attack_value){m_attack = a_attack_value; }
void soldier::set_min_attack(int a_min_attack){ m_min_attack = a_min_attack; }
void soldier::set_max_attack(int a_max_attack){m_max_attack = a_max_attack; }
void soldier::set_randomized_damage(int a_randomized_damage){ m_randomized_damage = a_randomized_damage; }
//set name and alive status
void soldier::set_name(std::string a_name){ m_name = a_name; }
void soldier::set_alive_status(bool a_alive_status){ m_alive_status = a_alive_status; }
// target receives damage, and if health is below 0, set it to 0
void soldier::take_damage(const int a_damage)
{
	m_health -= a_damage;
	if ( m_health < 0 ) { m_health = 0; }
}
// attack damage
void soldier::attack(soldier& a_squad) const { a_squad.take_damage(m_attack); }

// target will receive randomized damage between a min and max
void soldier::attack_target(soldier& a_target)
{
	m_randomized_damage = rand() % (m_max_attack - m_min_attack) + m_min_attack;
	a_target.take_damage(m_randomized_damage);
}