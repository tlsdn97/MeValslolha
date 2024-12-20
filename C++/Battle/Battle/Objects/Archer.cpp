#include "../framework.h"
#include "Archer.h"

// �������� �� Archer�� 50���� Ȯ���� ġ��Ÿ ������
Archer::Archer(int hp, int atk)
: Player(hp, atk, "Archer")
{
}

Archer::~Archer()
{
	cout << "Archer �Ҹ�!!" << endl;
}

void Archer::Attack(shared_ptr<Creature> p)
{
	int randNum = rand() % 100; // 0 ~ 99
	cout << this->_name << "�� " << p->GetName() << "���� ������ �õ��մϴ�." << endl;
	if (randNum <= 49)
	{
		cout << "Archer�� ũ��Ƽ�� ������!!!" << endl;
		p->TakeDamage(shared_from_this(), this->_attack * 2.0f);
	}
	else
	{
		p->TakeDamage(shared_from_this(), this->_attack);
	}

}
