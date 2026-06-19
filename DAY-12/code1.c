/* C Program to write function for palindrome */

#include <stdio.h>
int reverseNumber(int number){
    int reversed = 0;
    while (number !=0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}
int main(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number == reverseNumber(number)){
        printf("%d is a palindrome number.\n", number);
    }
    else{
        printf("%d is not a palindrome number.\n", number);
    }
return 0;
}
