#include <stdio.h>
#include "NumClass.h"

int main() {
	int x,y;
	scanf("%d %d", &x, &y);
	printf("Armstrong numbers::");
	for(int i = x; i <= y; i++) {
		if(isArmstrong(i) == 1) {
			printf(" ");
			printf("%d", i);
		}
	}
	printf("\n");
	printf("Palindromes numbers:");
	for(int i=x ; i <= y;i++) {
		if(isPalindrome(i)==1) {
			printf(" ");
			printf("%d", i);
		}
	}
	printf("\n");
	printf("Prime numbers:");
	for(int i=x ; i <= y;i++) {
		if(isPrime(i) == 1) {
			printf(" ");
			printf("%d", i);
		}
	}
	printf("\n");
	printf("Strong numbers:");
	for(int i=x ; i <= y;i++) {
		if(isStrong(i) == 1) {
			printf(" ");
			printf("%d", i);
		}
	}
}
