#include "framework.h"
#include "Cannon.h"

#include "Barrel.h"

Cannon::Cannon()
{
	_body = make_shared<RectCollider>(Vector2D(), Vector2D(120, 70));
	_barrel = make_shared<Barrel>(150);
	//_barrel = make_shared<Line>(Vector2D(), Vector2D());
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	Move();
	RotateBarrel();
	Fire();


	_body->Update();
	
	_barrel->Update();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
}

void Cannon::Move()
{
	if (GetAsyncKeyState('A') & 0x8001)
	{
		Vector2D left = Vector2D(-1, 0);
		AddPos(left * _speed);
	}

	if (GetAsyncKeyState('D') & 0x8001)
	{
		Vector2D right = Vector2D(1, 0);
		AddPos(right * _speed);
	}

	_barrel->UpdateBody(_body->center);

}

void Cannon::RotateBarrel()
{
	if (GetAsyncKeyState('W') & 0x8001)
	{
		_angle += 0.07f;
	}

	if (GetAsyncKeyState('S') & 0x8001)
	{
		_angle -= 0.07f;
	}

	_barrel->SetDir(Vector2D(cosf(_angle), -sinf(_angle)));

}

void Cannon::Fire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		Vector2D space = Vector2D(1, 0);
		AddPos(space * _speed);
	}
}