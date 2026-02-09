#include <stdio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "Enemy.h"




int main(int argc,const char * argv[]){
	 SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	Enemy enemy;
	enemy.initialize();
	for (int i = 0; i < 3; ++i)
	{
		enemy.update();
	}
	return 0;
}

