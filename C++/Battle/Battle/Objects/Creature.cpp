#include "framework.h"
#include "Creature.h"

Creature::Creature()
: _hp(0), _attack(0), _name("")
{
}

Creature::Creature(int hp, int attack, string name)
: _hp(hp), _attack(attack), _name(name)
{
}

Creature::~Creature()
{
}

void Creature::PrintInfo()
{
	cout << "NAME : " << this->_name << endl;
	cout << "HP : " << this->_hp << endl;
	cout << "ATK : " << this->_attack << endl;
}

void Creature::SetInfo(int hp, int attack, string name)
{
	// this : �� �Լ��� ȣ���� ��ü�� ����Ű�� ������
	this->_hp = hp;
	this->_attack = attack;
	this->_name = name;
}

void Creature::Attack(shared_ptr<Creature> other)
{
	cout << this->_name << "�� " << other->_name << "���� ������ �õ��մϴ�." << endl;
	other->TakeDamage(shared_from_this(), this->_attack);
}

void Creature::TakeDamage(shared_ptr<Creature> attacker, int amount)
{
	int afterHp = _hp - amount;

	SetHp(afterHp);
	cout << _name << "��(��) " << attacker->_name << "���� " << amount << "��ŭ�� �������� �Ծ����ϴ�." << endl;
}

void Creature::SetHp(int hp)
{
	if (hp < 0)
	{
		_hp = 0;
		return;
	}
	_hp = hp;
}
