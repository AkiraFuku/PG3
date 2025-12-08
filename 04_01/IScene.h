#pragma once

#include <KamataEngine.h>
#include <Novice.h>
#include <vector>
using namespace KamataEngine;
// シーン名の定義
enum SCENE {
	TITLE,
	STAGE,
	CLEAR,
};
class IScene
{
	protected:
	// シーン番号を管理する変数
	static int sceneNo_;
	
    // 共通のリソース
    static int numberGraphs_[10];
	public:
	// 仮想デストラクタ（必須）
	virtual ~IScene() ;

	// 初期化処理
	virtual void Init() = 0;

	// 更新処理 (キー入力を受け取る)
	virtual void Update(char* keys, char* preKeys) = 0;

	// 描画処理
	virtual void Draw() = 0;

	// 現在のシーン番号を取得（マネージャーがこれを見て切り替えを判断する）
	int GetSceneNo() const { return sceneNo_; }

    // 共通機能：数字描画 (実装はcppで行う)
    void numberDraw(Vector2 pos, int width, int i, const std::vector<int>& numberArray);

};

