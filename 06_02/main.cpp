#include <Novice.h>
#include <vector>
#include <queue>
#include <thread>
#include<condition_variable>
#include <mutex>
#include <map>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

const char kWindowTitle[] = "学籍番号";
uint32_t kNumBlockVertical = 10;
// ブロックの列数
uint32_t kNumBlockHorizontal = 5;
float kBlockWidth = 32.0f;
float kBlockHeight = 32.0f;
struct MapChipData {
	std::vector<std::vector<int>> data; ///< マップチップデータ

};

MapChipData LoadMapChipCsv(const std::string& filePath) {
	MapChipData Result;
	Result.data.resize(kNumBlockVertical); // 先に縦の配列を用意しておく

	std::ifstream file(filePath);
	assert(file.is_open());

	for (uint32_t i = 0; i < kNumBlockVertical; i++) {
		for (uint32_t j = 0; j < kNumBlockHorizontal; j++) {

			int value;
			file >> value; // まず数字（0か1）を読む

			Result.data[i].push_back(value); // 配列に入れる

			// 行の最後（右端）でなければ、後ろにカンマがあるので空読みして捨てる
			if (j < kNumBlockHorizontal - 1) {
				char comma;
				file >> comma; // ',' を吸い取って捨てる
			}
		}
	}

	file.close();
	return Result;

}


void DrawMapChip(MapChipData data) {
	if (data.data.empty()) return;
	for (uint32_t i = 0; i < kNumBlockVertical; i++) {
		for (uint32_t j = 0; j < kNumBlockVertical; j++) {
			// 安全対策: データが存在するか確認
			if (i < data.data.size() && j < data.data[i].size()) {
				if (data.data[i][j] == 1) {
					// jが横(X), iが縦(Y)
					int x = j * static_cast<int>(kBlockWidth);
					int y = i * static_cast<int>(kBlockHeight);
					int w = static_cast<int>(kBlockWidth);
					int h = static_cast<int>(kBlockHeight);

					Novice::DrawBox(x, y, w, h, 0.0f, WHITE, kFillModeSolid);
				}
			}
		}
	}

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	std::mutex mutex;

	MapChipData m;
	std::mutex mtx;
	bool isDataReady = false; // ロード完了フラグ

	std::thread th([&]() {
		MapChipData loadedData = LoadMapChipCsv("Map.csv");

		// データの書き込み時は鍵をかける（排他制御）
		std::lock_guard<std::mutex> lock(mtx);
		m = loadedData;
		isDataReady = true; // 準備完了

		});


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



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		std::lock_guard<std::mutex> lock(mtx);
		if (isDataReady) {
			DrawMapChip(m);
		} else {
			Novice::ScreenPrintf(0, 0, "Loading...");
		}
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

th.join();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
