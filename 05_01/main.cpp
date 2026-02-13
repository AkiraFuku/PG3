#include <Novice.h>

#include "Player.h"
#include "InputHandler.h"
#include "Command.h"
const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	InputHandler* inputHandler=nullptr;
	inputHandler=new InputHandler();
	inputHandler->AssignMoveLeftCommand2PlesskeyA();
	inputHandler->AssignMoveRightCommand2PlesskeyD();
	ICommand*iCommand=nullptr;
	Player*player=nullptr;
	player=new Player();
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		iCommand=inputHandler->HandleInput();
		if (iCommand)
		{
			iCommand->Exec(*player);
		}
		player->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	
	delete inputHandler;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
