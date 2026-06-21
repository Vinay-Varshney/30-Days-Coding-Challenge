/* C Program  to frequency  of an element. */

#include <stdio.h>
int main(){
    int size, i, target, count = 0;
    printf("Enter size of  the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements in the array:\n", size);
    for(i=0; i<size; i++){
    scanf("%d", &arr[i]);
}
printf("Enter the elements to find its frequency: ");
scanf("%d", &target);
for ( i = 0; i < size; i++)
{
    if(arr[i] == target){
        count++;
    }
}
printf("Frequency of %d = %d\n",target,count);
return 0;
}