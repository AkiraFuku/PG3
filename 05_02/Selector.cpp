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

	Novice::DrawBox(mapX_*size_,mapY_*size_,size_,size_,0.0f,RED,kFillModeSolid);
}
void Selector::Move(int x, int y)
{
	mapX_+=x;
	mapY_+=y;

}
void Selector::SelectUnit()
{
}
;