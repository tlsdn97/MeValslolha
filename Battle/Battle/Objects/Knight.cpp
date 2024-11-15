#include "../framework.h"
#include "Knight.h"


Knight::Knight(int hp, int atk)

: Player(hp, atk, "Knight")
, _maxHp(hp)
{

}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	
	Creature::Attack(other);

	
	float ratio = (float)_hp / (float)_maxHp;
	if (ratio < 0.5f)
	{
		cout << "Knight의 연속 공격!!!" << endl;
		Creature::Attack(other);
	}
}
