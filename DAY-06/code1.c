/* C Program to convert decimal to binary */

#include <stdio.h>
long long convert(long long);
int main(){
    int decimal, binary[32], i = 0;
    printf("Enter a decimal number: ");
    scanf("%lld", &decimal);
    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }

    // Display the binary number
    printf("Binary equivalent: ");
    for(int j = i -1; j >= 0; j--)
    printf("%d", binary[j]);

    printf("\n");

    return 0;
}