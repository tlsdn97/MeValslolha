#pragma once

// header : �����
// cpp : �����

class Player : public Creature
{
public:
	Player();
	Player(int hp, int attack, string name);
	~Player();

	void RangeAttack(shared_ptr<Creature> arr[], int size);
};

