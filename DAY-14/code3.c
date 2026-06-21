/* C Program to find second largest elements */

#include <stdio.h>
#include <limits.h> // Required for INT_MIN
int main(){
    int size;
    printf("Enter the number of elements in the array: ");
    if(scanf("%d", &size) !=1 || size<2) {
        printf ("Error: Array must have at least 2 elements.\n");
        return 1;
    }
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(int i =0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    // Initialize both tracking variables to the smallest possible integer value
    int first_largest = INT_MIN;
    int second_largest = INT_MIN;

    // Single pass through the array to find both elements
    for(int i =0; i<size; i++){
        if(arr[i] > first_largest){
            // The old largest becomes the new second largest
            second_largest = first_largest;
            // Update the largest elements
            first_largest = arr[i];
        }
        // if the element is smaller than the largest but bigger than the second largest
            else if (arr[i] > second_largest && arr[i] != first_largest){
                second_largest = arr[i];
            }
        }
    
        printf("\nLargest element: %d\n",first_largest);
        if (second_largest == INT_MIN){
            printf("Second largest elements does not exist(all elements may be identical).\n");
        }
        else{
            printf("Second largest element: %d\n", second_largest);
        }
        return 0;
            }