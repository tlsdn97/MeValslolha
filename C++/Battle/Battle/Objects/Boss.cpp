#include "framework.h"
#include "Boss.h"

Boss::Boss(int hp, int atk)
: Goblin(hp, atk, "Hop")
{
}

void Boss::BossRangeAttack()
{
	// ���� ��� _playerTable���� ����
	auto removeIter = std::remove_if(_playerTable.begin(), _playerTable.end(), [](const PlayerInfo& element)->bool 
		{
			// weakPtr�� ��ȿ����
			if (element.player.expired() == true)
				return false;

			// weakPtr�κ��� shared_ptr ��������
			shared_ptr<Creature> p = element.player.lock();

			if (p->IsDead() == true)
				return true;
			return false;
		});

	_playerTable.erase(removeIter, _playerTable.end());

	// std::sort(_playerTable.begin(), _playerTable.end(), less<PlayerInfo>());
	std::sort(_playerTable.begin(), _playerTable.end(), [](const PlayerInfo& a, const PlayerInfo& b)-> bool 
		{
			if (a.totalDamage > b.totalDamage)
				return true;
			return false;
		});

	// Print
	AggroUI();

	for (int i = 0; i < _attackRange; i++)
	{
		if (i >= _playerTable.size())
			break;

		if (_playerTable[i].player.expired() == true)
			continue;

		shared_ptr<Creature> curPlayer = _playerTable[i].player.lock();
		this->Attack(curPlayer);
	}
}

void Boss::TakeDamage(shared_ptr<Creature> attacker, int amount)
{
	auto iter = std::find_if(_playerTable.begin(), _playerTable.end(), [attacker](const PlayerInfo& info) -> bool
		{
			if (info.player.expired() == true)
				return false;

			if (info.player.lock()->GetName() == attacker->GetName())
				return true;
			return false;
		});

	// ó������ attacker ���� �¾��� ��
	if (iter == _playerTable.end())
	{
		PlayerInfo curInfo;
		curInfo.player = attacker;
		curInfo.totalDamage = amount;

		_playerTable.push_back(curInfo);
	}
	// �̹� ���� �� ���̻� ���ȴ� ��
	else
	{
		iter->totalDamage += amount;
	}

}

void Boss::AggroUI()
{
	cout << "---------Aggro--------" << endl;
	for (auto info : _playerTable)
	{
		if (info.player.expired() == true)
			continue;

		cout << info.player.lock()->GetName() << " : " << info.totalDamage << endl;
	}
	cout << "----------------------" << endl;
}
