#pragma once
#include "IShape.h"
class Cirle :public IShape
{
	public:
	Cirle(float radius) ;
	~Cirle() = default;
	void Size() override;
	void Draw() override;

private:
	float radius_;
	float size_;

};

