#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
	int lenght = lenght1(num);
	int f = 0;
	for (int i = 0; i<=lenght ; i++) {
		f += pow(num%10,lenght);
		num/=10;
	}
	if (f == num) {
		return 1;
	}
	return 0;
}

int isPalindrome(int num) {
	int lenght = lenght1(num);
	int x = 0;
	int y = 1;
	int temp = num;
	for (int i = 0; i<=lenght; i++) {
		x += (temp % 10) * y;
		y *= 10;
		temp /= 10;
	}
	if (x == num) {
		return 1;
	}
	return 0;
}
int lenght1 (int num) {
	int x = 0;
	while (num!=0)
	{
		x++;
		num/10;
	}
	return x;
}

