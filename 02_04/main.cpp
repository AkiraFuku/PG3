//#include <stdio.h>
//#include <Windows.h>
//#include <stdlib.h>
//#include <time.h>
//#include <fcntl.h>
//#include <io.h>
//#include <functional>
//#include <wchar.h>
//
//int main(int argc, const char* argv[]) {
//	_setmode(_fileno(stdout), _O_U16TEXT); // UTF-16 出力に切り替え
//
//
//
//	auto ShowResult = [](int roll, int userGuess) {
//		wprintf(L"出目は%dでした。\n", roll);
//
//		if (roll % 2 == userGuess) {
//			wprintf(L"正解\n");
//		} else {
//			wprintf(L"不正解\n");
//		}
//		};
//
//	auto DelayReveal = [](std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
//		Sleep(delayMs);
//		fn(roll, userGuess);
//		};
//
//	srand((unsigned int)time(NULL));
//	int userGuess = -1;
//
//	wprintf(L"偶数なら0、奇数なら1を入力してください: ");
//
//	scanf_s("%d", &userGuess);
//
//	int roll = rand() % 6 + 1;
//	wprintf(L"サイコロを振っています...\n");
//	DelayReveal(ShowResult, 3000, roll, userGuess);
//	return 0;
//}
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>


void DelayReveal(void(*fn)(int,int),unsigned int delayMs, int roll, int userGuess);

void ShowResult(int roll, int userGuess){
	wprintf(L"出目は%dでした。\n", roll );

	if(roll%2==userGuess){
		wprintf(L"正解\n" );
	}else{
		wprintf(L"不正解\n" );
	}
}

int main(){
	int modeResult = _setmode(_fileno(stdout), _O_U16TEXT);
	if (modeResult == -1) {
		fwprintf(stderr, L"_setmode に失敗しました。\n");
		return 1;
	}
	srand((unsigned int)time(NULL));
	int userGuess=-1;

		wprintf(L"偶数なら0、奇数なら1を入力してください: ");
	
		scanf_s("%d", &userGuess);

	int roll = rand() % 6 + 1;
	wprintf(L"サイコロを振っています...\n");
	DelayReveal(ShowResult, 3000, roll, userGuess);
	return 0;
}

void DelayReveal(void(*fn)(int,int),unsigned int delayMs, int roll, int userGuess){
	Sleep(delayMs);
	fn(roll, userGuess);
	
}