#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int num) {
	if (num == 2) {
		return 1;
	}
	int i = 3;
	while (i*i <= num) {
		if (num % i == 0) {
			return 0;
		}
	i++;
	}
	return 1;
}
int isStrong (int num) {
	int factorial(int) ;
	int x = 0; //sum of the factorial
	int temp = num;
	while (temp != 0) {
		int y = temp%10;
		x += factorial(y);
		temp /= 10;	
	}
	if (x == num) {
		return 1;
	}
	return 0;
	
}
int factorial (int num) {
	int f = 1;
	for (int i = 1; i<=num; i++) {
		f*= i;
	}
	return f;
}
