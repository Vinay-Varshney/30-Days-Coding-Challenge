#include <stdio.h>
int main(){
    int n,i;
    unsigned long long fact = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Shows  error if the user enters  a negative integer
    if (n<0)
    printf("Error! Factorial of a negative no. doesn't exist.");
    else{
        for(i=1; i<=n; ++i){
            fact *= i;
        }
        printf("Factorial of %d = %llu", n, fact);
    }
    return 0;
}