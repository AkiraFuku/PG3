#pragma once
#include "IScene.h"
class StageScene :public IScene
{
private:
	int mapW_=40;
	int mapH_=20;
	int size=30;
public:

	~StageScene() override;
	void Init()override;

	// 更新処理 (キー入力を受け取る)
	void Update() override;

	// 描画処理
	void Draw() override;

};

