/* C Program to print repeated-number pattern */

#include <stdio.h>
int main(){
int i, j, rows;
printf("Enter the rows: ");
scanf("%d", &rows);
for(i = 1; i <= rows; ++i){
    for (j = 1; j <=i; ++j)
    {
        printf("%d ",i);
    }
    printf("\n");
    }
    return 0;
}