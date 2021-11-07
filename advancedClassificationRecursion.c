#include <stdio.h>
#include <math.h>
#include "NumClass.h"
#define true 1
#define false 0

/**this function is called by isArmstrong function and check out with recursion if 
* a given number "n" is equal to the sum of is digit powered by the number of digits of n
**/
int myArmstrong(int n,int b, int c){// b represents the sum of the numbers
	int length = length1(n);// the length of n with using log identity
	if(length<=0) {// if the length is 0
		return b;//return the sum
	}
	b += pow(n%10, c);//c represents the number of digits in n
	return myArmstrong(n/10, b, c);//get the next digit in n and the sum and the number of digits
        }
        /**this function get number n and return 1 if it armstrong number and 0 if not*/
int isArmstrong(int n){
	int length = length1(n);
	if(myArmstrong(n,0,length)==n)
		return true;
	return false;
}
/** this function checks out if a number is palindrome by checking out if the reversed number is equal to the number*/
int isPalindrome(int n) {
	int length = length1(n);
	if(n==reverse(n,0,length)) {
		return true;
	}
	return false;
}

/**this function using recursion to reverse the number*/
int reverse(int num,int reversed, int length){
	if(length==0)
	return reversed;
	reversed= (reversed*10)+ (num%10);
	return reverse(num/10, reversed, length-1);
}

int length1 (int num) {
	int x = 0;
	while (num!=0)
	{
		x++;
		num /= 10;
	}
	return x;
}
