#pragma once

// ��� ��� Ŭ���� : ����������
class Cannon // : public RectCollider
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void RotateBarrel();
	void Fire();

	void SetPos(Vector2D pos) { _body->center = pos; }

	void AddPos(Vector2D vec) { _body->center += vec; }

private:
	shared_ptr<RectCollider> _body; // ������Ʈ ���� ... ����Ƽ
	float _speed = 5.f;
	float _angle = 0.0f;


	shared_ptr<class Barrel> _barrel;
	shared_ptr<class Ball> _ball;

};

