#pragma once
#include <KamataEngine.h>
#include <Novice.h>
#include <math.h>
#include<stdlib.h>

#include"Scoer.h"
using namespace KamataEngine;

enum SCENE{
		TITLE,
		STAGE,
		CLEAR,
	};
typedef struct Background {
	Vector2 pos;
	int graphHandle;
} Background;
class IScene {
protected:
	//　シーン番号
	static int sceneNo;
	int numberGraphs_[10];

public:
	virtual void Init()=0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene() = default;

	int GetSceneNo() const {
		return sceneNo;
	}
	void numberDraw(Vector2 pos,int width,int i);
private:
	//int frameCount_;
	//int timer_;
	//int hieScoer_;
	//int BgHandle_;
	//int playHandle_;
	//Background backGround_[2];


	//Player* player_;
	//Enemy* enemy_[10];
	//unsigned int titleGlaph_;
	//unsigned int endGraph_;
	//unsigned int akaDaikonn_;
	//unsigned int uiGlaph_;
	std::vector<int> numberArray_[3];

	//isScene();
	//~isScene();
	
	//void Update(const char* keys,const char*preKeys);
	//void Draw();
	//int scene_;
};
