#pragma once
#include "IScene.h"
class CrearScene :public IScene
{
	public:
	void Init() override;
	void Update() override;
	void Draw() override;
};

