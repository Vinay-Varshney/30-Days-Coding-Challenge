/* C Program to find largest and smallest element */

#include <stdio.h>
int main(){
    int arr[100];
    int size, i;
    int largest, smallest;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    if(size<=0 || size>100){
        printf("invalid size! please enter a size between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d elements: \n", size);
    for(i=0; i<size; i++){
        printf("Elements [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    //Assume the first elements is both the largest and smallest
    largest = arr[0];
    smallest = arr[0];
    
    // Traverse the array to compare each element
    for(i=1; i<size; i++){
        if (arr[i]> largest){
            largest = arr[i];
        }
        if (arr[i] < smallest){
            smallest = arr[i];
        }
    }
    printf("\nLargest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    return 0;
}