#include "IScene.h"

int IScene::sceneNo_ = TITLE;

IScene::~IScene(){}

int IScene::numberGraphs_[10] = {
	Novice::LoadTexture("./Resources/images/nungrph/0.png"),
	Novice::LoadTexture("./Resources/images/nungrph/1.png"),
	Novice::LoadTexture("./Resources/images/nungrph/2.png"),
	Novice::LoadTexture("./Resources/images/nungrph/3.png"),
	Novice::LoadTexture("./Resources/images/nungrph/4.png"),
	Novice::LoadTexture("./Resources/images/nungrph/5.png"),
	Novice::LoadTexture("./Resources/images/nungrph/6.png"),
	Novice::LoadTexture("./Resources/images/nungrph/7.png"),
	Novice::LoadTexture("./Resources/images/nungrph/8.png"),
	Novice::LoadTexture("./Resources/images/nungrph/9.png"),
};

void IScene::numberDraw(Vector2 pos, int width, int i, const std::vector<int>& numberArray) {
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