#include <stdio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "Enemy.h"




int main(int argc,const char * argv[]){
	int modeResult = _setmode(_fileno(stdout), _O_U16TEXT);
	if (modeResult == -1) {
		fwprintf(stderr, L"_setmode に失敗しました。\n");
		return 1;
	}
	Enemy enemy;
	enemy.initialize();
	for (int i = 0; i < 3; ++i)
	{
		enemy.update();
	}
	return 0;
}

