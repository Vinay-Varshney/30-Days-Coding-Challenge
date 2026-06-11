/* C Program to find largest prime factor */

#include <stdio.h>
#include <math.h>
long long maxPrimeFactors(long long n){
    // initialize the max. prime factor, variable with the lowest one
    long long maxPrime = -1;

    while (n % 2 == 0){
        maxPrime = 2;
        n >>= 1;
    }
    for(int i =3; i * i <= n; i+= 2){
        while(n % i == 0){
            maxPrime = i;
             n = n / i;
        }
    }
    if (n > 2)
    maxPrime = n;
    return maxPrime;
} 
// Driver Program to test above function
int main(){
    long long  n = 625;
    printf("%lld\n", maxPrimeFactors(n));

    n= 108;
    printf("%lld\n", maxPrimeFactors(n));

    return 0;
}