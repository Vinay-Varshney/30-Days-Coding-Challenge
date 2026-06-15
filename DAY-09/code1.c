/* C Program to print reverse star pattern */

#include <stdio.h>
int main(){
int i, j, rows;
printf("Enter the rows: ");
scanf("%d", &rows);
for(i = 1; i <= rows; ++i){
    for (j = i; j <=rows; ++j)
    {
        printf("*");
    }
    printf("\n");
    }
    return 0;
}