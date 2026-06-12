/* C Program to find x^n without pow() */

#include <stdio.h>
int main(){
    double base;
    int exp;
    double result = 1.0;

    printf("Enter a base number: ");
    scanf("%lf", &base);

    printf("Enter an exponent: ");
    scanf("%d", &exp);
    int original_exp = exp;
    
    while (exp != 0){
        result *= base;
        --exp;
    }
    printf("Answer = %.0lf\n", result);
    return 0;
}