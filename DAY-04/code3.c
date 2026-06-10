/* C Program to check Armstrong number */

#include <stdio.h>
int main(){
    int num, original, remainder, result=0;
    printf("Enter a three-digit integer");
    scanf("%d", &num);
    original = num;

    while (original !=0) {
        // remainder contains the last digit
        remainder = original % 10;
        result += remainder * remainder * remainder;
        
        // removing last digit from the original number
        original /= 10;
    }
    if( result == num)
    printf("%d is an Armstrong number.", num);
    else
    printf("%d is not an Armstrong number");
    return 0; 
    // 371 is an armstrong number >> Check
}