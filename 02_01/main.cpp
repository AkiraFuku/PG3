#include <stdio.h>

template<typename Type>
Type Min(Type a,Type b){
	return (a < b) ? a : b;
}

int main(){

	int a = 10;
	int b = 20;
	printf("Min(%d,%d)=%d\n",a,b,Min<int>(a,b));
	float c = 3.14f;
	float d = 2.71f;
	printf("Min(%.2f,%.2f)=%.2f\n",c,d,Min<float>(c,d));
	double e = 3.141592;
	double f = 2.718281;
	printf("Min(%.5f,%.5f)=%.5f\n", e, f, Min<double>(e, f));
	return 0;


};