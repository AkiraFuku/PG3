#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
#include <functional>


void DelayReveal(void(*fn)(int,int),unsigned int delayMs, int roll, int userGuess);

//void ShowResult(int roll, int userGuess){
//	wprintf(L"出目は%dでした。\n", roll );
//
//	if(roll%2==userGuess){
//		wprintf(L"正解\n" );
//	}else{
//		wprintf(L"不正解\n" );
//	}
//}

int main(int argc,const char * argv[]){
	_setmode(_fileno(stdout), _O_U16TEXT);

	auto ShowResult = [](int roll, int userGuess) {
		wprintf(L"出目は%dでした。\n", roll );
		if(roll%2==userGuess){
			wprintf(L"正解\n" );
		}else{
			wprintf(L"不正解\n" );
		}
		};
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
	
