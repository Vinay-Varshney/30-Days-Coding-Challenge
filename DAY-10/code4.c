/* C Program to print number pyramid */

#include <stdio.h>
int main(){
int i, j;
char alph= 'A'; // Initialize a character variable to 'A'
int n, blk; // Declare variable for user input and block counter
int ctr=1; // initialize a counter
printf("Enter the number of letters (less than 26) in the pyramid: ");
scanf("%d", &n);
for(i = 1; i <= n; ++i){
    for(blk = 1; blk <= n-i; ++blk){
        printf(" ");
    }
    for(j = 0; j <= (ctr/2); ++j){
        printf("%c", alph++);
}
alph = alph-2; // Decrement the character after printing half
     for(j = 0; j < (ctr/2); ++j){
        printf("%c", alph--);
}
ctr = ctr + 2; // Increment the counter for the next row
        alph = 'A'; // Reset the character to 'A' for the next row

    printf("\n");
}
return 0;
}