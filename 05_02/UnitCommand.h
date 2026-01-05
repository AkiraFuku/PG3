#pragma once
#include "IStageSceneCommand.h"
class Unit;
class Selector;

class UnitMoveCommand:public IStageSceneCommand{
public :
	UnitMoveCommand(Unit* unit,int x,int y);
	void Exec()override;
private:
	Unit* unit_;
	int x_;
	int y_;

};
class UnitMoveEndCommand:public IStageSceneCommand
{
public:
	UnitMoveEndCommand(Unit* unit,Selector* selector);
	void Exec()override;
private:
	Unit* unit_;
	Selector* selector_;
};

