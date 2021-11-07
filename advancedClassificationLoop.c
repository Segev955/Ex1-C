#include <stdio.h>
#include <math.h>
#include "NumClass.h"
#define true 1
#define false 0


int isArmstrong(int num) {
	int length = length1(num);
	int f = 0; //sum of the nth powers
	int temp = num;
	while (temp!=0) {
		f += pow(temp%10,length); 
		temp/=10; 
	}
	if (f == num) {
		return true;
	}
	return false;
}

int isPalindrome(int num) {
	int x = 0; //reverse number
	int temp = num;
	while (temp!=0) {
		x *= 10;
		x += (temp % 10);
		temp /= 10;
	}
	if (x == num) {
		return true;
	}
	return false;
}
//checking int length
int length1 (int num) {
	int x = 0;
	while (num!=0)
	{
		x++;
		num /= 10;
	}
	return x;
}
