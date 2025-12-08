#pragma once
#include<memory>
#include "IScene.h"
#include"TitleScene.h"
#include"StageScene.h"
#include"ClearScene.h"
#include<Novice.h>
class GameManager
{
private:
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNo_;
	int prevSceneNo_;
public:
	GameManager();
	~GameManager();
	int Run();
};

