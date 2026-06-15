/* C Program to print reverse number triangle */

#include <stdio.h>
int main(){
int i, j, rows;
printf("Enter the rows: ");
scanf("%d", &rows);
for(i = 0; i <=rows; ++i){
    for (j = 0; j <=rows-i; ++j)
    {
        printf("%d ",j+1);
    }
    printf("\n");
    }
    return 0;
}