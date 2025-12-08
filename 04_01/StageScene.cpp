#include "StageScene.h"

void StageScene::Init()
{
	timer_ = 60;
	frameCount_ = 0;
	player_ = std::make_unique<Player>();
	player_->reset();

	for (int i = 0; i < 10; i++) {
		enemy_[i] = std::make_unique<Enemy>();

		enemy_[i]->reset();
	}
	uiGlaph_ = Novice::LoadTexture("./Resources/images/reseet.png");
	akaDaikonn_ = Novice::LoadTexture("./Resources/images/lifedaikonn.png");
		BgHandle_ = Novice::LoadAudio("./Resources/Sounds/dotabatare-su.mp3");


	for (int i = 0; i < 10; i++)
	{
		numberGraphs_[i] = Novice::LoadTexture(("./Resources/images/nungrph/" + std::to_string(i) + ".png").c_str());
	}
	for (int i = 0; i < 2; i++) {
		backGround_[i].graphHandle = Novice::LoadTexture("./Resources/images/backgraund.png");
	}
	backGround_[0].pos.x = 0.0f;
	backGround_[0].pos.y = 0.0f;
	backGround_[1].pos.x = 0.0f;
	backGround_[1].pos.y = -720.0f;

}

void StageScene::Update()
{
	if (!Novice::IsPlayingAudio(playHandle_))
	{
		playHandle_ = Novice::PlayAudio(BgHandle_, true, 0.5f);
	}
	if (player_->GetLife() <= 0 || timer_ <= 0)
	{
		Novice::StopAudio(playHandle_);
		sceneNo == CLEAR;
	}
	frameCount_++;
	if (frameCount_ >= 60) {
		frameCount_ = 0;
		timer_--;
	}
	///プレイヤーの移動///
	player_->Update(input->GetKeys());


	//================================================================
	// 敵の更新処理
	//================================================================

	for (int i = 0; i < 10; i++) {
		enemy_[i]->Update();
	}

	//================================================================
	// 当たり判定
	//================================================================

	for (int i = 0; i < 10; i++) {


		if (enemy_[i]->GetIsAlive()) {
			//弾丸//
			for (int j = 0; j < bulltNum_; j++) {
				if (player_->GetBullets(j)->isShot_) {
					if (enemy_[i]->GetRadius() + player_->GetBullets(j)->GetRadius() >=
						Lengeth(enemy_[i]->GetPos(), player_->GetBullets(j)->GetPos())) {
						enemy_[i]->SetIsAlive(false);
						player_->GetBullets(j)->isShot_ = false;
						player_->SetScoer(player_->GetScoer() + 100);
						if (!Novice::IsPlayingAudio(playHandle_)) {
							playHandle_ = Novice::PlayAudio(enemy_[i]->GetSound(), false, 0.5f);
						}
					}
				}
			}


		}


	}



	//プレイヤーの当たり判定
	for (int i = 0; i < 10; i++) {
		if (player_->GetHitCoolTime() <= 0) {
			if (enemy_[i]->GetIsAlive()) {
				if (player_->GetLife() > 0) {
					if (!player_->GetIsHit()) {
						if (player_->GetRadius() + enemy_[i]->GetRadius() >=
							Lengeth(player_->GetPos(), enemy_[i]->GetPos())) {
							player_->SetIsHit(true);
							player_->SetLife(player_->GetLife() - 1);
							player_->SetHitCoolTime(180);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 2; i++) {

		backGround_[i].pos.y += 5.0f;

		if (backGround_[i].pos.y == kStageHeight)
		{
			backGround_[i].pos.y = -kStageHeight;
		}
	}




}

void StageScene::Draw()
{
	//背景///
	for (int i = 0; i < 2; i++) {

		Novice::DrawSprite(
			static_cast<int>(backGround_[i].pos.x),
			static_cast<int>(backGround_[i].pos.y),
			backGround_[i].graphHandle,
			1.0f,
			1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}
	//================================================================
	// 敵の描画処理
	//================================================================
	for (int i = 0; i < 10; i++) {
		enemy_[i]->Draw();
	}



	///プレイヤー描画///
	player_->Draw();

	//UI
	Novice::DrawSprite(kStageWidth, 0, uiGlaph_, 1.0f, 1.0f, 0.0f, WHITE);

	numberDraw({ 890.0f  , 350.0f }, 40, 2);

	numberDraw({ 890.0f  , 250.0f }, 40, 1);
	for (int i = 0; i < player_->GetLife(); i++) {
		Novice::DrawSprite(i * 40 + 900, 400, akaDaikonn_,
			1.0f,
			1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}
}
