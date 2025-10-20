#include <stdio.h>

// 再帰的な賃金計算関数

int CalculateSalary(int salary,int tortal,  int normal, int hour) {
   
	tortal += salary;
    printf("Hour=%d, Salary=%d, Total=%d,NormalToatal%d\n", hour, salary, tortal,normal*hour);
    if (tortal < normal*hour) {
	    return CalculateSalary(salary*2-50, tortal, normal, hour+1);
    }
        return tortal;
}

int main(){
    int normalSalary = 1226;
    int salary = 100;
	int tortal = 0;
    int hour = 1;
    printf("Final Salary=%d\n", CalculateSalary(salary, tortal,normalSalary, hour));
}

