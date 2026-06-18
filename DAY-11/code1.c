/* C Program to write function to find sum of two numbers */

#include <stdio.h>
int findSum(int num1, int num2);
int main(){
int num1, num2, result;
printf("Enter first number: ");
scanf("%d", &num1);

printf("Enter second number: ");
scanf("%d", &num2);

result = findSum(num1, num2);

printf("The sum of %d and %d is: %d\n", num1, num2, result);
return 0;
}
int findSum(int a, int b){
    return a + b;
}