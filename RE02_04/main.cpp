#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
#include <functional>


int main(int argc, const char* argv[]) {
	/*int modeResult = _setmode(_fileno(stdout), _O_U16TEXT);
	if (modeResult == -1) {
		fwprintf(stderr, L"_setmode に失敗しました。\n");
		return 1;
	}*/
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	srand((unsigned int)time(NULL));


	auto ShowResult = [](int roll, int userGuess) {
		printf("出目は%dでした。\n", roll);

		if (roll % 2 == userGuess) {
			printf("正解\n");
		} else {
			printf("不正解\n");
		}
	};

	auto DelayReveal = [](std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
		Sleep(delayMs);
		fn(roll, userGuess);
	};

	int userGuess = -1;

	printf("偶数なら0、奇数なら1を入力してください: ");

	scanf_s("%d", &userGuess);

	int roll = rand() % 6 + 1;
	printf("サイコロを振っています...\n");
	DelayReveal(ShowResult, 3000, roll, userGuess);
	return 0;
}

