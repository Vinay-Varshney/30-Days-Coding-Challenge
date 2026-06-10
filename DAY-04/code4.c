/* C Program to print Armstrong numbers in range */

#include <stdio.h>
#include <math.h>
int main(){
    int low, high, number, original, remainder, count=0;
    double result = 0.0;
    printf("Enter two numbers(intervals)");
    scanf("%d %d ", &low, &high);
    printf("Armstrong numbers between %d and %d are: ", low, high);
    
// swap numbers if high<low
if (high<low){
    high += low;
    low = high - low;
    high -= low;
}
    // iterate number from (low +1) to (high -1)
    // in each itration, check if number is armstrong
    for (number = low + 1 ; number < high; ++number){
        original = number;

        // number of digits calculation
        while (original != 0){
        original /=10;
        ++count;
        }
       original = number;

       // result contains sum of nth power of individual digits
       while (original !=0){
       remainder = original % 10;
       result += pow(remainder, count);
       original /= 10;
    }
    // Check if number is equal to the sum of nth power of individual digits
    if ((int)result == number){
        printf("%d ", number);
    } 
        // resetting the values
        count = 0;
        result = 0;

}
return 0;
}