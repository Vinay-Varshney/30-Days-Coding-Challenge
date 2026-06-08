/* C Program to check whether a number is  palindrome */

#include <stdio.h>
int main(){
int n, reverse=0, remainder, original;
    printf("Enter a number: ");
    scanf("%d", &n);
    original = n;

    // Reversed inter is stored in reverse variable
    while (n != 0){
        remainder = n % 10;
        reverse = reverse *10 +remainder;
        n /= 10;
    }
    // Palindrome if original and reverse are equal

    if (original == reverse ) 
        printf("%d is a Palindrome.", original);
    else
    printf("%d is not a Palindrome.", original);
    
    return 0;
}