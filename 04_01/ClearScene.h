#pragma once
#include "IScene.h"
#include <vector>

class ClearScene : public IScene {
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

	// StageSceneからスコアを受け取るための静的メソッド
	static void SetFinalScore(int score) { finalScore_ = score; }

private:
	int endGraph_;
	static int highScore_; // ハイスコア（プログラム起動中は保持）
	static int finalScore_; // 今回のスコア

	std::vector<int> numberArray_[3]; // 表示用配列
};