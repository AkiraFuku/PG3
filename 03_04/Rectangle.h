#pragma once
#include "IShape.h"
class Rectangle :public IShape
{
	public:
	Rectangle(float width,float height ) ;
	~Rectangle() = default;
	void Size() override;
	void Draw() override;
private:
	float width_;
	float height_;
	float size_;
};

