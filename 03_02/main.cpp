
#include <stdio.h>
#include "Compare.h"

int main(){
	

	Compare<int, double> comp1(10, 20.6);
	printf("Minimum value: %d\n", comp1.Min());
	Compare<double, float> comp2(30.5,31.2f );
	printf("Minimum value: %f\n", comp2.Min());
	Compare<float, int> comp3(15.5f, 10);
	printf("Minimum value: %f\n", comp3.Min());
	Compare<int, int> comp4(25, 30);
	printf("Minimum value: %d\n", comp4.Min());
	Compare<float, float> comp5(12.7f, 9.3f);
	printf("Minimum value: %f\n", comp5.Min());
	Compare<double, double> comp6(45.8, 45.1);
	printf("Minimum value: %f\n", comp6.Min());




	return 0;
}