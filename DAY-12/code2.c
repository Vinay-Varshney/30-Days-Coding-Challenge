/* C Program to write function for armstrong */

#include <stdio.h>
#include <math.h>
int isArmstrong(int num);
    int countDigits(int num);

    int main(){
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number)){
        printf("%d is a Armstrong number.\n", number);
    }
    else{
        printf("%d is not a Armstrong number.\n", number);
    }
return 0;
}

int isArmstrong(int num){
    int originalNum = num;
    int digits = countDigits(num);
    int sum = 0;

    while (num >0){
        int remainder = num%10;
        sum +=  round(pow(remainder, digits));
        num /= 10;
     }
    return (sum == originalNum);
}

    int countDigits(int num) {
        int count = 0;
        if(num ==0) return 1;

        while (num !=0){
            num /= 10;
            count++;
        }
        return count; 
}