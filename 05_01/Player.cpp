#include "Player.h"
#include "Novice.h"
void Player::Init(){

	pos_={50.0f,100.0f};
}
void Player::Update(){}
void Player::Draw(){

	Novice::DrawBox(static_cast<int>(pos_.x-radius),static_cast<int>(pos_.y-radius),static_cast<int>(radius*2.0f),static_cast<int>(radius*2.0f),0.0f,WHITE,kFillModeSolid);

}

void Player::MoveRight()
{
	pos_.x+=Speed_;
}

void Player::MoveLeft()
{
	pos_.x-=Speed_;
}
