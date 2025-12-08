#include "Player.h"

void Player::Init(){}
void Player::Update(){}
void Player::Draw(){}

void Player::MoveRight()
{
	pos_.x+=Speed_;
}

void Player::MoveLeft()
{
	pos_.x-=Speed_;
}
