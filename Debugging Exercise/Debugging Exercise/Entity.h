#pragma once
#ifndef ENTITY_H
#define ENTITY_H
class Entity
{
public:
	Entity();
	~Entity();

	virtual void attack(Entity *a_target);
	virtual int get_attack_damage();
	virtual int get_health();
	virtual void takeDamage(int damage);
	bool isAlive();

protected:
	int health;
	int attack_damage;
	int maxHealth;
};
#endif
