#include "Cirle.h"
#include <stdio.h>

Cirle::Cirle(float radius)
{
	radius_ = radius;
}

void Cirle::Size()
{
	size_ = 3.14f * radius_ * radius_;
}

void Cirle::Draw()
{
	Size();
	printf("Circle drawn with size: %.2f\n", size_);
}
