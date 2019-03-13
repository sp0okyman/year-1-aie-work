#include "Entity.h"

Entity::Entity()
{
	health = 0;
	attack_damage = 0;
}
Entity::~Entity(){}

void Entity::attack(Entity *a_target)
{
	a_target->takeDamage(attack_damage);
}

int Entity::get_health()
{
	return health;
}

int Entity::get_attack_damage()
{
	return attack_damage;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

bool Entity::isAlive()
{
	return health > 0;
}
