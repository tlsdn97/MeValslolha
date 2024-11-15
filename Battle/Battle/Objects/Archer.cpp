#include "../framework.h"
#include "Archer.h"

// 공격했을 때 Archer는 50프로 확률로 치명타 터지게
Archer::Archer(int hp, int atk)
: Player(hp, atk, "Archer")
{
}

Archer::~Archer()
{
	cout << "Archer 소멸!!" << endl;
}

void Archer::Attack(Creature* p)
{
	int randNum = rand() % 100; // 0 ~ 99
	cout << this->_name << "이 " << p->GetName() << "에게 공격을 시도합니다." << endl;
	if (randNum <= 49)
	{
		cout << "Archer의 크리티컬 데미지!!!" << endl;
		p->TakeDamage(this, this->_attack * 2.0f);
	}
	else
	{
		p->TakeDamage(this, this->_attack);
	}

}
