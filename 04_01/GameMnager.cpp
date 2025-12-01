#include "GameMnager.h"
#include<Novice.h>
#include "InputManager.h"



GameMnager::GameMnager()
{
	sceneArr_[TITLE]=std::make_unique<TitleScene>();
	sceneArr_[STAGE]=std::make_unique<StageScene>();
	sceneArr_[CLEAR]=std::make_unique<CrearScene>();
	currentSceneNo_=TITLE;
	
}

GameMnager::~GameMnager()
{
}

int GameMnager::Run()
{
	while (Novice::ProcessMessage()==0){

		Novice::BeginFrame();
		
		inputManager->Update();
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_){
			sceneArr_[currentSceneNo_]->Init();
		}
		sceneArr_[currentSceneNo_]->Update();
		sceneArr_[currentSceneNo_]->Draw();
		Novice::EndFrame();
		if (inputManager->GetKeys()[DIK_ESCAPE]==0&&
			inputManager->GetPreKeys()[DIK_ESCAPE]!=0)
		{
			break;

		}
	}

	return 0;
}
