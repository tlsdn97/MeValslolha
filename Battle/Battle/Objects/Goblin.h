#pragma once
class Goblin : public Monster
{
public:
	Goblin(int hp, int attack, string name);
	~Goblin();

	virtual void Attack(Creature* other) override;
};

