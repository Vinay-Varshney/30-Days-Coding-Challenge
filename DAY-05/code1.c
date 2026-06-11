/* C Program to check whether a number is perfect number or not */

#include <stdio.h>
int main(){
    int i, num, sum=0;
    printf("Enter any number to check perfect number: ");
    scanf("%d", &num);

    for (i = 1; i <= num / 2; i++)
    {
        // if i is a divisor of num
        if (num%i == 0)
        {
            sum += i;
        }
    }

    // check whether the sum of proper divisors is equal to num
    if (sum == num && num > 0)
    {
        printf("%d is Perfect Number", num);
    }
    else
{
    printf("%d is not Perfect Number", num);
}
    return 0;
}

/* Perfect Number : A positive integer that equals the sum of its 
proper divisors.
Ex: (6) ->> Divisors- 1,2,3  sum check: 1+2+3= 6 */ 
