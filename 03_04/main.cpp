#include <stdio.h>	
#include "IShape.h"
#include "Cirle.h"
#include "Rectangle.h"

int main() {
	IShape* shape1 = new Cirle(5.0f);
	
	shape1->Draw();
	IShape* shape2 = new Rectangle(4.0f, 6.0f);
	shape2->Draw();
	delete shape1;
	delete shape2;



	return 0;
	
}