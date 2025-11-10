#pragma once
enum class state
	{
		Approach,
		Shoot,
		leave


	};
class Enemy
{
public:

	

	void initialize();
	void update();

	void Approach();
	void Shoot();
	void leave();


private:

	static void(Enemy::*stateFunctions[])();

	state phase_;

	
};

