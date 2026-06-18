/* C Program to write function to find factorial */

#include <stdio.h>
unsigned long long findFactorialRecursive(int n);
int main(){
    int num;
    printf("Eneter a positive integer: ");
    scanf("%d", &num);
    if(num<0){
        printf("Error: Factorial of negative number does not exist.\n");
    } else{
        unsigned long long result = findFactorialRecursive(num);
        printf("Factorial of %d = %llu\n", num, result);
    }
    return 0;
}

unsigned long long findFactorialRecursive(int n){
    if(n<=1){
        return 1;
    }
    return n * findFactorialRecursive(n-1);
}