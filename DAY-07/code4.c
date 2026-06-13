/* C Program to reverse a number using recursion */

#include <stdio.h>
#include <math.h>
int reverse(int num);
int main(){
int num, rev;
printf("Enter any number: ");
scanf("%d", &num);

// call the function to reverse number
rev = reverse(num);
printf("Reverse of %d = %d", num, rev);
return 0; 
}

int reverse(int num)
{
    // find total digits in num
    int digit = (int) log10(num);
    if (num == 0)
    return 0;

    return((num%10 * pow(10, digit)) + reverse(num/10));
}