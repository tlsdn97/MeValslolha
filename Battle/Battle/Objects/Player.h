#pragma once

// header : 선언부
// cpp : 실행부

class Player : public Creature
{
public:
	Player();
	Player(int hp, int attack, string name);
	~Player();

};

