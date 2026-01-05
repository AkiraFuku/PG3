#pragma once
class Unit;
class Selector;
class IStageSceneCommand;
class StageSceneInputHandler
{
private:
	char keys_[255]={0};
	char preKeys_[255]={0};

	Selector* selector_;
	Unit* unit_;
public:
	StageSceneInputHandler();
	void UpdateKeyState();

	IStageSceneCommand* SelectorHandleInput(Selector* selector);
	IStageSceneCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();



};

