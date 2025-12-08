#include "StageScene.h"
#include "ClearScene.h" // スコア受け渡しのためにインクルード
#include <Novice.h>

StageScene::StageScene() {
	// メモリ確保
	player_ = new Player();
	for (int i = 0; i < 10; i++) {
		enemy_[i] = new Enemy();
	}
}

StageScene::~StageScene() {
	// メモリ解放
	delete player_;
	for (int i = 0; i < 10; i++) {
		delete enemy_[i];
	}
}

void StageScene::Init() {
	sceneNo_ = STAGE;

	// テクスチャ読み込み
	uiGraph_ = Novice::LoadTexture("./Resources/images/reseet.png");
	lifeGraph_ = Novice::LoadTexture("./Resources/images/lifedaikonn.png");
	bgHandle_ = Novice::LoadAudio("./Resources/Sounds/dotabatare-su.mp3");

	// 背景設定
	for (int i = 0; i < 2; i++) {
		backGround_[i].graphHandle = Novice::LoadTexture("./Resources/images/backgraund.png");
		backGround_[i].pos = { 0.0f, (i == 0) ? 0.0f : -720.0f };
	}

	// パラメータ初期化
	playHandle_ = -1;
	timer_ = 60;
	frameCount_ = 0;

	// オブジェクトのリセット
	player_->reset();
	for (int i = 0; i < 10; i++) {
		enemy_[i]->reset();
	}
}

void StageScene::Update(char* keys, char* preKeys) {

	preKeys;
	// BGM再生
	if (!Novice::IsPlayingAudio(playHandle_)) {
		playHandle_ = Novice::PlayAudio(bgHandle_, true, 0.5f);
	}

	// ゲームオーバーまたはタイムアップ判定
	if (player_->GetLife() <= 0 || timer_ <= 0) {
		Novice::StopAudio(playHandle_);
		
		// スコアをClearSceneに渡す（静的変数などを利用）
		ClearScene::SetFinalScore(player_->GetScoer());
		
		sceneNo_ = CLEAR; // シーン遷移フラグ
		return;
	}

	// タイマー更新
	frameCount_++;
	if (frameCount_ >= 60) {
		frameCount_ = 0;
		timer_--;
	}

	// プレイヤー更新
	player_->Update(keys);

	// 敵更新
	for (int i = 0; i < 10; i++) {
		enemy_[i]->Update();
	}

	// 当たり判定処理
	CheckCollision();

	// 背景スクロール
	for (int i = 0; i < 2; i++) {
		backGround_[i].pos.y += 5.0f;
		if (backGround_[i].pos.y >= 720.0f) { // kStageHeightの代わり
			backGround_[i].pos.y = -720.0f;
		}
	}

	// UI用数値配列の更新
	numberArray_[1] = NumberArray(timer_);
	numberArray_[2] = NumberArray(player_->GetScoer());
}

void StageScene::CheckCollision() {
	// 弾 vs 敵
	for (int i = 0; i < 10; i++) {
		if (enemy_[i]->GetIsAlive()) {
			for (int j = 0; j < 10; j++) { // 弾数上限
				if (player_->GetBullets(j)->isShot_) {
					float dist = Lengeth(enemy_[i]->GetPos(), player_->GetBullets(j)->GetPos());
					if (enemy_[i]->GetRadius() + player_->GetBullets(j)->GetRadius() >= dist) {
						
						enemy_[i]->SetIsAlive(false);
						player_->GetBullets(j)->isShot_ = false;
						player_->SetScoer(player_->GetScoer() + 100);
						
						// 敵の撃破音再生（簡易実装）
						Novice::PlayAudio(enemy_[i]->GetSound(), false, 0.5f);
					}
				}
			}
		}
	}

	// 敵 vs プレイヤー
	for (int i = 0; i < 10; i++) {
		if (player_->GetHitCoolTime() <= 0 && enemy_[i]->GetIsAlive() && player_->GetLife() > 0) {
			if (!player_->GetIsHit()) {
				float dist = Lengeth(player_->GetPos(), enemy_[i]->GetPos());
				if (player_->GetRadius() + enemy_[i]->GetRadius() >= dist) {
					player_->SetIsHit(true);
					player_->SetLife(player_->GetLife() - 1);
					player_->SetHitCoolTime(180);
				}
			}
		}
	}
}

void StageScene::Draw() {
	// 背景描画
	for (int i = 0; i < 2; i++) {
		Novice::DrawSprite((int)backGround_[i].pos.x, (int)backGround_[i].pos.y, 
			backGround_[i].graphHandle, 1.0f, 1.0f, 0.0f, WHITE);
	}

	// 敵描画
	for (int i = 0; i < 10; i++) {
		enemy_[i]->Draw();
	}

	// プレイヤー描画
	player_->Draw();

	// UI描画
	Novice::DrawSprite(1280, 0, uiGraph_, 1.0f, 1.0f, 0.0f, WHITE); // kStageWidth
	
	// 数値描画 (ISceneの機能を使用)
	numberDraw({ 890.0f, 350.0f }, 40,numberArray_[2]); // スコア
	numberDraw({ 890.0f, 250.0f }, 40, numberArray_[1]); // タイマー

	// ライフ描画
	for (int i = 0; i < player_->GetLife(); i++) {
		Novice::DrawSprite(i * 40 + 900, 400, lifeGraph_, 1.0f, 1.0f, 0.0f, WHITE);
	}
}