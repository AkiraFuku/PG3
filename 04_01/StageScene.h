#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class StageScene : public IScene {
public:
	StageScene();
	~StageScene() override;

	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

private:
	// ゲーム内オブジェクト
	Player* player_;
	Enemy* enemy_[10];

	// リソースハンドル
	int bgHandle_;      // BGM
	int playHandle_;    // 再生中の音声ハンドル
	int uiGraph_;       // リセットUIなど
	int lifeGraph_;     // 体力表示用（赤大根）
	Background backGround_[2]; // 背景

	// ゲームステート管理
	int timer_;
	int frameCount_;

	// 描画用ヘルパー配列
	std::vector<int> numberArray_[3]; // 0:HighScore, 1:Timer, 2:Score

	// 当たり判定関数 (内部利用)
	void CheckCollision();
};