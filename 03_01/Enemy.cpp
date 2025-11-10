#include "Enemy.h"
#include <Windows.h>
#include <stdlib.h>
#include <functional>



void Enemy::initialize()
{
	phase_ = state::Approach;

}

void Enemy::update()
{
	(this->*stateFunctions[static_cast<size_t>(phase_)])();

	if (phase_!=state::leave)
	{
		phase_ = static_cast<state>((static_cast<size_t>(phase_) + 1));
	}

	

	
	const char* stateNames[] = { "Approach", "Shoot", "leave" };

	wprintf(L"次の行動は%S\n", stateNames[static_cast<size_t>(phase_)] );
}

void Enemy::Approach(){	

	wprintf(L"接近中\n" );
}

void Enemy::Shoot()
{
		wprintf(L"射撃\n" );
}

void Enemy::leave()
{
	wprintf(L"離脱\n");
}

void(Enemy::*Enemy::stateFunctions[])() =
{
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::leave
};
