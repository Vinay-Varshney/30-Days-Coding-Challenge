/* C Program to find product of digits */

#include <stdio.h>
int main(){
    int num;
    long long product =1ll;
    
    printf("Enter the  number to calculate product of digit: ");
    scanf("%d", &num);

    product = (num == 0 ? 0 : 1ll);
    // Repeat the steps till num becomes 0.

    while(num !=0){
    // Get the last digit from num and multiplies to product
    product = product * (num % 10);
    // Remove last digit from num
    num = num / 10;
    }

    printf("Product of digits = %lld", product);
    return 0;
}