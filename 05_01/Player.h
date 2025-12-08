#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;
class Player
{
private:
	Vector2 pos_;
	const float Speed_=50/60;
public:

	void Init();
	void Update();
	void Draw();
	void MoveRight();
	void MoveLeft();
};

