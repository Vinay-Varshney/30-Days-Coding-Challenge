/* C Program to recursive Fibonacci */

#include <stdio.h>
int main(){
int i, n;
// initialize first and second terms
int t1 = 0, t2 = 1;
// initialize the next term 
int nextTerm = t1 + t2;
printf("Enter the number of terms: ");
scanf("%d", &n);
// Print first two terms from user
printf("Fibonacci Series: %d, %d, ", t1, t2);

// Print 3rd to nth terms
for(i = 3; i <= n; ++i){
    printf("%d, ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
}
return 0;
}
