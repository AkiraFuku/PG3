#pragma once
#include "Disaster.h"
class Earthquake :public Disaster
{
	public:
	Earthquake();
	~Earthquake();
	void warn() override;
};

