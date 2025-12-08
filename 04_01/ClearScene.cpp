#include "ClearScene.h"
#include <Novice.h>
#include "Scoer.h"
// 静的変数の初期化
int ClearScene::highScore_ = 0;
int ClearScene::finalScore_ = 0;

void ClearScene::Init() {
	sceneNo_ = CLEAR;
	endGraph_ = Novice::LoadTexture("./Resources/images/end.png");

	// ハイスコア更新処理
	if (finalScore_ > highScore_) {
		highScore_ = finalScore_;
	}

	numberArray_[0] = NumberArray(highScore_);
	numberArray_[2] = NumberArray(finalScore_);
}

void ClearScene::Update(char* keys, char* preKeys) {
	// スペースキーでタイトルへ戻る
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneNo_ = TITLE;
	}
}

void ClearScene::Draw() {
	// ゲームオーバー画面
	Novice::DrawSprite(0, 0, endGraph_, 1.0f, 1.0f, 0.0f, WHITE);

	// スコア描画 (ISceneのnumberDrawを使用)
	// 第3引数は numberArray_ のインデックス
	
	// 今回のスコア 
	numberDraw({ 300.0f, 500.0f }, 40, 2,numberArray_[2]);

	// ハイスコア 
	numberDraw({ 300.0f, 300.0f }, 40, 0,numberArray_[0]);
}