#pragma once

class Unit;
class Selector
{
private:
	int mapX_;
	int mapY_;
	int mapSize_=30;
	int selectMode_;
	

	Unit* unit_;
	Unit* selectedUnit_;

public:
	Selector();
	void Init();
	void Update();
	void Draw();

	void Move(int x,int y);
	void SelectUnit();

	Unit* GetUnitList(){return unit_;};
	void SetUnitList(Unit* unit){unit_=unit;};

};

