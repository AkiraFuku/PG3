#pragma once
#include"Command.h"
class InputHandler
{
public:
	~InputHandler();
	ICommand*HandleInput();
	void AssignMoveLeftCommand2PlesskeyA();
	void AssignMoveRightCommand2PlesskeyD();
private:
	ICommand *pressKeyD_;
	ICommand *pressKeyA_;


	
};

