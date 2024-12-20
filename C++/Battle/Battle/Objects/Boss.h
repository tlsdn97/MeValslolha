#pragma once

// ������ ��׷� �ý����� �߰�
// 1. ��׷ζ�°� ����(���� ������ �ʿ��Ѱ�)
// - ���� ���ȴ���
// - ��ŭ ���ȴ���

struct PlayerInfo
{
	bool operator<(const PlayerInfo& other) const
	{
		if (totalDamage < other.totalDamage)
			return true;
		return false;
	}

	weak_ptr<Creature>	player;
	int			totalDamage;
};

class Boss : public Goblin
{
public:
	Boss(int hp, int atk);

	void BossRangeAttack();
	virtual void TakeDamage(shared_ptr<Creature> attcker, int amount) override;

private:
	void AggroUI();

	vector<PlayerInfo> _playerTable;

	int _attackRange = 4;
};

