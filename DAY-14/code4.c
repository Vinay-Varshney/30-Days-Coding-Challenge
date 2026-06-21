/* C Program to find duplicates in array */

#include <stdio.h>
void findDuplicates(int arr[], int size){
    // Array to keep track of  already counted/printed elements
    int visited[size];
    for (int i =0; i<size; i++){
        visited[i] = 0; // Initialize all elements as not visited 
    }
    int foundDuplicate = 0;
    printf("Duplicate elements in the array: ");

    for(int i =0; i<size; i++){
        if (visited[i] ==1){
            continue;
        }
        int count = 1 ;
        for(int j = i+1; j<size; j++){
            if(arr[i] == arr[j]){
                count++;
                visited[j]=1;
            }
        }
        if (count >1){
            printf("%d ", arr[i]);
            foundDuplicate = 1;
        }
    }
    if (!foundDuplicate){
        printf("None");
    }
    printf("\n");
}
int main(){
    int arr[]= {4, 2, 7, 4, 8, 2, 3, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i =0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    findDuplicates(arr, size);
    return 0;
}