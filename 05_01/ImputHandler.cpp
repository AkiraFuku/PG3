#include "ImputHandler.h"
#include "Novice.h"
ICommand* ImputHandler::HandleInput()
{
	if (Novice::CheckHitKey(DIK_D))
	{
		return pressKeyD_;
	}
	return nullptr;
}

void ImputHandler::AssignMoveLeftCommand2PlesskeyA()
{
	ICommand* command = new MoveLeftCommand();
	pressKeyA_ = command;
}

void ImputHandler::AssignMoveRightCommand2PlesskeyD()
{
	ICommand* command = new MoveRightCommand();
	pressKeyD_ = command;
}
