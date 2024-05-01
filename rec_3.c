// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(char binary[]){
    int decimal = 0;
    int power = 0;
    size_t length = strlen(binary);
    for (int i = length-1; i >= 0 ; --i){
        int bit = binary[i]-'0';
        decimal += bit * pow(2,power);
        power += 1;
    }
    return decimal;
}

int main() {
    // Write C code here
    char bin[32];
    printf("Enter binary: ");
    scanf("%s",bin);
    printf("decimal = %d\n", binaryToDecimal(bin));
    int num, expo;
    int product = 1;
    printf("Enter integer: ");
    scanf("%d",&num);
    printf("Enter exponent: ");
    scanf("%d", &expo);
    for(int i = 0; i < expo; ++i){
        product = product * num;
    }
    printf("Num^exponent = %d",product);
    return 0;
}