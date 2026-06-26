/* C Program for Bubble sort */

#include <stdio.h>
// Function to perform Bubble Sort
void bubbleSort(float prices[], int n) {
   for (int i = 0; i < n - 1; i++) {
       // Flag to optimize the algorithm
       int swapped = 0;
       for (int j = 0; j < n - i - 1; j++) {
           if (prices[j] > prices[j + 1]) {
               // Swap adjacent elements if they are in the wrong order
               float temp = prices[j];
               prices[j] = prices[j + 1];
               prices[j + 1] = temp;
               swapped = 1;
           }
       }
       // If no two elements were swapped, break early
       if (!swapped) break;
   }
}
int main() {
   // Example product prices
   float prices[] = {19.99, 5.49, 12.99, 7.99, 25.00};
   int n = sizeof(prices) / sizeof(prices[0]);
   printf("Original Prices:\n");
   for (int i = 0; i < n; i++) {
       printf("%.2f ", prices[i]);
   }
   // Sorting the prices
   bubbleSort(prices, n);
   printf("\n\nSorted Prices:\n");
   for (int i = 0; i < n; i++) {
       printf("%.2f ", prices[i]);
   }
   return 0;
}