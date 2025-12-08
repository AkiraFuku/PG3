#include "IScene.h"

int IScene::sceneNo_ = TITLE;

IScene::~IScene(){}

int IScene::numberGraphs_[10] = {0};
void IScene::LoadResources() {
    numberGraphs_[0] = Novice::LoadTexture("./Resources/images/nungrph/0.png");
    numberGraphs_[1] = Novice::LoadTexture("./Resources/images/nungrph/1.png");
    numberGraphs_[2] = Novice::LoadTexture("./Resources/images/nungrph/2.png");
    numberGraphs_[3] = Novice::LoadTexture("./Resources/images/nungrph/3.png");
    numberGraphs_[4] = Novice::LoadTexture("./Resources/images/nungrph/4.png");
    numberGraphs_[5] = Novice::LoadTexture("./Resources/images/nungrph/5.png");
    numberGraphs_[6] = Novice::LoadTexture("./Resources/images/nungrph/6.png");
    numberGraphs_[7] = Novice::LoadTexture("./Resources/images/nungrph/7.png");
    numberGraphs_[8] = Novice::LoadTexture("./Resources/images/nungrph/8.png");
    numberGraphs_[9] = Novice::LoadTexture("./Resources/images/nungrph/9.png");
}

void IScene::numberDraw(Vector2 pos, int width, const std::vector<int>& numberArray) {
	for (int j = 0; j <static_cast<int>( numberArray.size()); ++j) {
		int digit = numberArray[j];
		Novice::DrawSprite(static_cast<int>(pos.x) + width * static_cast<int>(j),
						   static_cast<int>(pos.y),
						   numberGraphs_[digit],
						   1.0f,
						   1.0f,
						   0.0f,
						   WHITE);
	}
}