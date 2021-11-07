#include <stdio.h>
#include <math.h>
#include "NumClass.h"
#define true 1
#define false 0

int isPrime(int num) {
	if (num < 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
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
		return true;
	}
	return false;
	
}
int factorial (int num) {
	int f = 1;
	for (int i = 1; i<=num; i++) {
		f*= i;
	}
	return f;
}
