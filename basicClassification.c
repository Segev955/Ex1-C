#include <stdio.h>
#include <math.h>
#include "NumClass.h"
#define true 1
#define false 0

int isPrime(int num) {
	if (num < 2) {
		return false;
	}
	if (num == 2) {
		return true;
	}
	int i = 3;
	while (i*i <= num) {
		if (num % i == 0) {
			return false;
		}
	i++;
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
