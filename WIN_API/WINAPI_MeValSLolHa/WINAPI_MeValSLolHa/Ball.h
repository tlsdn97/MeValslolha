#pragma once
class Ball 
{
public:

	Ball();
	~Ball();

	void UpdateBody(Vector2D bodyCenter) { _ball->_end = bodyCenter; }

	void Update();
	void Render(HDC hdc	);dd

	

private:

	shared_ptr<CircleCollider> _ball;
	float _speed = 5.f;
	float _angle = 0.0f;

};

