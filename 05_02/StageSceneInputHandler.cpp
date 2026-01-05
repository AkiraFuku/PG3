#include "StageSceneInputHandler.h"

StageSceneInputHandler::StageSceneInputHandler()
{
}

void StageSceneInputHandler::UpdateKeyState()
{
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector)
{
	selector;
	return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit)
{
	unit;
	return nullptr;
}

bool StageSceneInputHandler::CheckUndoStatus()
{
	return false;
}
