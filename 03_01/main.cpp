#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#include "Enemy.h"

int main(int argc,const char * argv[]){
	int modeResult = _setmode(_fileno(stdout), _O_U16TEXT);
	if (modeResult == -1) {
		fwprintf(stderr, L"_setmode に失敗しました。\n");
		return 1;
	}
	
	 modeResult = _setmode(_fileno(stdin),  _O_U16TEXT);
	if (modeResult == -1) {
		fwprintf(stderr, L"_setmode に失敗しました。\n");
		return 1;
	}


	Enemy enemy;
	enemy.initialize();
	for (int i = 0; i < 5; ++i)
	{
		enemy.update();
	}


	
	return 0;
}
