#include "TitleScene.h"
#include <Novice.h>

#include "Graph.h"

void TitleScene::Init()
{
	titleGlaph_ = Novice::LoadTexture("./Resources/images/RRtitle.png");
}

void TitleScene::Update()
{
	if (inputManager->GetKeys()[DIK_SPACE]&&!inputManager->GetPreKeys()[DIK_SPACE]) {
		

		IScene::sceneNo = STAGE;	
	}
}

void TitleScene::Draw()
{
	Novice::DrawSprite(0, 0, titleGlaph_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
