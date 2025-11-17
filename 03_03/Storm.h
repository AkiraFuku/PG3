#pragma once
#include "Disaster.h"
class Storm :public Disaster
{
	public:
	Storm();
	~Storm();
	void warn() override;
};

