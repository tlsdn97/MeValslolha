#include "framework.h"
#include "Goblin.h"

Goblin::Goblin(int hp, int attack, string name)
: Monster()
{
	_hp = hp;
	_attack = attack;
	_name = name;
}

Goblin::~Goblin()
{
	cout << "고블린 소멸!" << endl;
}

void Goblin::Attack(Creature* other)
{

	cout << "고블린 Attack!!" << endl;
	Creature::Attack(other);
}
