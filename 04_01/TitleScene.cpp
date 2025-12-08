#include "TitleScene.h"
void TitleScene::Init() {
    sceneNo_ = TITLE; // 自分はタイトル
    titleGraph_ = Novice::LoadTexture("./Resources/images/RRtitle.png");
}

void TitleScene::Update(char* keys, char* preKeys) {
    // スペースキーでステージへ
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        sceneNo_ = STAGE; 
    }
}

void TitleScene::Draw() {
    Novice::DrawSprite(0, 0, titleGraph_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

}