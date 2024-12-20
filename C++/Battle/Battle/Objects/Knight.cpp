#include "../framework.h"
#include "Knight.h"

// Knight�� �ڱ�ü���� 50���� ������ �� ���ݷ� 2��
Knight::Knight(int hp, int atk, string name)
// �ڽ��� �����ڿ��� �Ͻ������� �θ��� �⺻�����ڸ� ȣ��
: Player(hp, atk, name)
, _maxHp(hp)
{
// �θ��� ��������� ���� �ʱ�ȭ �������� �ʱ�ȭ���� ���Ѵ�.
}

Knight::~Knight()
{
}

void Knight::Attack(shared_ptr<Creature> other)
{
	// :: ���� ���� ������
	Creature::Attack(other);

	// maxHp
	// hp
	float ratio = (float)_hp / (float)_maxHp;
	if (ratio < 0.5f)
	{
		cout << "Knight�� ���� ����!!!" << endl;
		Creature::Attack(other);
	}
}
