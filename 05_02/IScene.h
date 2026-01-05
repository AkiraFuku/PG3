#pragma once
class IScene
{
	public:
	// 仮想デストラクタ（必須）
		virtual ~IScene() {};

	// 初期化処理
	virtual void Init() = 0;

	// 更新処理 (キー入力を受け取る)
	virtual void Update() = 0;

	// 描画処理
	virtual void Draw() = 0;
};

