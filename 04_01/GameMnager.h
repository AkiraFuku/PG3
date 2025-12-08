#pragma once
#include<memory>
#include"IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "CrearScene.h"
class GameMnager
{
private:
	std::unique_ptr<IScene> sceneArr_[3];
	std::unique_ptr<InputManager> inputManager;
	int currentSceneNo_;
	int prevSceneNo_;
public:


	GameMnager();
	~GameMnager();
	int Run();
};

