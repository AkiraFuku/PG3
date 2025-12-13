#include "InputHandler.h"
#include "Novice.h"
ICommand* InputHandler::HandleInput()
{
	if (Novice::CheckHitKey(DIK_D))
	{
		return pressKeyD_;
	}
	if (Novice::CheckHitKey(DIK_A))
	{
		return pressKeyA_;
	}
	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PlesskeyA()
{
	ICommand* command = new MoveLeftCommand();
	pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PlesskeyD()
{
	ICommand* command = new MoveRightCommand();
	pressKeyD_ = command;
}
