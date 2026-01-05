#include "Selector.h"
#include "Unit.h"
#include "Novice.h"
Selector::Selector()
{
}

void Selector::Init(){

	mapX_=0;
	mapY_=0;
};

void Selector::Update(){};
void Selector::Draw(){

	Novice::DrawBox(mapX_*mapSize_,mapY_*mapSize_,mapSize_,mapSize_,0.0f,RED,kFillModeSolid);
}
void Selector::Move(int x, int y)
{
	mapX_+=x;
	mapY_+=y;

}
void Selector::SelectUnit()
{
	selectedUnit_ = nullptr;

	const int kMaxUnits = 10;

	for (int i = 0; i < kMaxUnits; i++)
	{
		

		// 3. Selectorの座標とUnitの座標が一致しているか判定
		// ※Unit側に座標取得ゲッターが必要
		if (unit_[i].GetMapX() == mapX_ && unit_[i].GetMapY() == mapY_)
		{
			// 4. 一致したら、そのユニットのアドレス(&)を代入
			selectedUnit_ = &unit_[i];
			
			// 見つかったのでループを抜ける
			break; 
		}
	}
}
;