#include "framework.h"
#include "Barrel.h"

Barrel::Barrel(float length)
	: _barrellength(length)
{
	_line = make_shared<Line>(Vector2D(), Vector2D());
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	_line->_end = _line->_start + _dir * _barrellength;

	_line->Update();
}

void Barrel::Render(HDC hdc)
{
	_line->Render(hdc);
}
