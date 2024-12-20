#include "framework.h"
#include "Ball.h"

Ball::Ball()

{
}

Ball::~Ball()
{
}

void Ball::Update()
{
	_ball->Update();
}

void Ball::Render(HDC hdc)
{
	_ball->Render(hdc);
}
