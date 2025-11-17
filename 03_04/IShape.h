#pragma once
class IShape
{
public:
	IShape() = default;
	~IShape() = default;
	virtual void Size()=0;
	virtual void Draw() = 0;
};

