#pragma once
class Ball 
{
public:

	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc	);

	void SetPos(Vector2D pos) { _circleCollider->center = pos; }
	void SetDir(Vector2D dir) { dir.Normalize(); _dir = dir; }
	void SetSpeed(float speed) { _speed = speed; }

	void Erase();

	void SetActive(bool value) { _fallingspeed = 0.0f; _isActive = value; }
	bool IsActive() { return _isActive; }


private:
	shared_ptr<CircleCollider> _circleCollider;

	Vector2D _dir = Vector2D(1, 0);
	float _speed = 3.0f;
	
	bool _isActive = false;
	float _fallingspeed = 0.0f;
	float _G = 1;
	

};

