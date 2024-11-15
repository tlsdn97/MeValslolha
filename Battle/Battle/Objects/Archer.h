#pragma once

class Archer : public Player
{
public:
	Archer(int hp, int atk);
	~Archer();

	virtual void Attack(Creature* p) override;

private:

};

