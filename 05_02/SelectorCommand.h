#pragma once
#include "IStageSceneCommand.h"
class Selector;

class SelectorMoveCommand:public IStageSceneCommand{
public :
	SelectorMoveCommand(Selector* selector,int x,int y);
	void Exec()override;
private:
	Selector* selector_;
	int x_;
	int y_;

};
class SelectUnitCommand:public IStageSceneCommand
{
public:
	SelectUnitCommand(Selector* selector);
	void Exec()override;
private:
	Selector* selector_;
};

