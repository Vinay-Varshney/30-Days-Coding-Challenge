/* C Program to check whether a number is Strong Number or not */

#include <stdio.h>
int main(){
int i, originalNum, num, lastDigit, sum;
long fact;
printf("Enter any number to check Strong Number: ");
scanf("%d", &num);
originalNum = num;
sum=0;

// Find sum of factorial of digits
while (num >0)
{
lastDigit = num % 10;
// Find factorial of last digit
fact = 1;
for(i=1; i<=lastDigit; i++){
    fact = fact * i;
}
// Add factorial to sum
sum = sum + fact;
num = num / 10;
}
// Check strong number condition
if(sum == originalNum)
{
    printf("%d is Strong Number", originalNum);
}
else 
{
    printf("%d is not Strong Number", originalNum);
}
return 0;
}

/* Strong Number : (Digit1)! + (Digit2)! + (Digit3)! +...+ (Digitn)!
   Ex: (145) ->> 1! + 4! + 5! = 145 */