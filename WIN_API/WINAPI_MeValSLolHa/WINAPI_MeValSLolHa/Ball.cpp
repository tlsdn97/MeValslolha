#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circleCollider = make_shared<CircleCollider>(Vector2D(), 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{ 
	if (_isActive == false) return;

		// if(�ð��� ������)
		// SetActive(false)
	
		// if(�ٴڿ� �ε�����)
		// SetActive(false)

	_circleCollider->center += _dir * _speed;
	_circleCollider->center.y += _fallingspeed;
	
	_fallingspeed += _G;

	_circleCollider->Update();

}

void Ball::Render(HDC hdc)
{
	if (_isActive == false) return;

	_circleCollider->Render(hdc);
}

void Ball::Erase()
{
	IsActive.erase
}


