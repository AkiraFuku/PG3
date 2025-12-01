#pragma once
#include "IScene.h"
#include "InputManager.h"
class TitleScene :public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
private:
	std::unique_ptr<InputManager> inputManager;
	unsigned int titleGlaph_;
};

