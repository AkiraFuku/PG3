#pragma once
#include "IScene.h"
#include <Novice.h>
#include "Player.h"
#include "Graph.h"
#include "enemy.h"
#include<time.h>
#include<memory>
#include "InputManager.h"

class StageScene :public IScene
{
	public:
	void Init() override;
	void Update() override;
	void Draw() override;
private:
	int frameCount_;
	int timer_;
	int playHandle_=-1;
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_[10];
	unsigned int uiGlaph_=-1;
	unsigned int akaDaikonn_=-1;
	int BgHandle_=-1;
	//unsigned int numberGraphs_[10];

	Background backGround_[2];

	std::unique_ptr<InputManager>input;

};

