#pragma once
#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>
class soldier
{

	// enum specialization fluff to add more character to these numbers.
	enum specialization { Rifleman, Demolitionist, Reconnaissance };
public:

	soldier();

	soldier(std::string a_name);

	~soldier();

	const int get_health() const;
	const int get_attack_value() const;
	const std::string get_name() const;
	const bool get_alive_status() const;
	specialization get_specialization() const;

	void set_health(int a_health);
	void set_attack_value(int a_attack_value);
	void set_name(std::string a_name);
	void set_alive_status(bool a_alive_status);
	void attack(soldier& a_Squad) const;

	void attack_target(soldier& a_target);


private:
	int m_health = 0;
	int m_attack = 0;
	bool m_if_alive = true;
	specialization m_specialization;

	std::string m_name;

	void take_damage(const int a_damage);

};
#endif // !SOLDIER_H
