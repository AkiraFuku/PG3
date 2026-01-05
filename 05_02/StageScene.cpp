#include "StageScene.h"
#include "Novice.h"
StageScene::~StageScene(){}
void StageScene::Init(){};
void StageScene::Update(){};
void StageScene::Draw(){

	for (int i = 0; i <mapW_ ; i++)
	{
		for (int j = 0; j < mapH_; j++)
		{
			Novice::DrawBox(i*size,j*size,size,size,0.0f,WHITE,kFillModeWireFrame);

		}

	}

}