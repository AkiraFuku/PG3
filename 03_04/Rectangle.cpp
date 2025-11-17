#include "Rectangle.h"
#include <stdio.h>
Rectangle::Rectangle(float width, float height)
{
	width_ = width;
	height_ = height;


}
void Rectangle::Size()
{
	size_ = width_ * height_;
}

void Rectangle::Draw()
{
	Size();	
	printf("Rectangle drawn with size: %.2f\n", size_);
}
