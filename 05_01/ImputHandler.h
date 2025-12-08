#pragma once
#include"Command.h"
class ImputHandler
{
public:
	ICommand*HandleInput();
	void AssignMoveLeftCommand2PlesskeyA();
	void AssignMoveRightCommand2PlesskeyD();
private:
	ICommand *pressKeyD_;
	ICommand *pressKeyA_;


	
};

