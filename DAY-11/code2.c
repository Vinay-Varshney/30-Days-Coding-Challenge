/* C Program to write function to find maximum */

#include <stdio.h>
int findMax(int num1, int num2);
int main(){
int a, b, max;

printf("Enter two integers: ");
scanf("%d %d", &a, &b);

max = findMax(a,b);

printf("The maximum number is: %d\n", max);
return 0;
}
int findMax(int num1, int num2){
    if(num1 > num2){
        return num1;
    } else {
        return num2;
    }
}