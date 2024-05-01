#include <stdio.h>

// Converts groups of 5 bits to their decimal equivalent
int groupOfBinaryToDecimal(char binary[]) {
    int decimal = 0;
    int value = 1;

    for (int i = 4; i >=0; i--) {
        if (binary[i] == '1') {
            decimal += value;
        }
        value *= 2;
    }
    return decimal;
}

// Converts decimal equivalents to their equivalent value in base-32 (0, 1 , 2....., V)
char decimalToAlphabetEquivalent(int decimal) {
    if (decimal < 10) {
        return decimal + '0';
    } else {
        return (decimal - 10) + 'A';
    }
}

// Overall function for binary to base-32 conversion
void binaryToBase32(char binary[]) {

    // finds the length of the binary string input
    int length = 0;
    while (binary[length] != '\0') {
        length++;
    }

    // edge case for 0
    int yesZero = 1;

    for (int l = 0; l < length; ++l){
        if (binary[l] != '0'){
            yesZero = 0;
            break;
        }
    }
    
    if (yesZero == 1){
        printf("0");
        return;
    }


    // finds how many leading zeroes we'd need to make groups of 5
    int leadingZeros = (5 - (length % 5)) % 5;


    // building a new string with the leading zeroes
    char new_binary[(length+leadingZeros)];

    int leadingZeroTracker = 1;

    for (int j = 0; j < leadingZeros; ++j) {
        new_binary[j] = '0';
    }

    for (int m = leadingZeros; m < length+leadingZeros; ++m) {
        new_binary[m] = binary[m-leadingZeros];
    }

    // splits the new binary string into groups of 5 bits and performs conversions
    for (int i = 0; i < length; i += 5) {
        char group[5];
        for (int j = 0; j < 5; j++) {
            group[j] = new_binary[i + j];
        }

        int decimal = groupOfBinaryToDecimal(group);
        char base32 = decimalToAlphabetEquivalent(decimal);

        
        // removes any leading zeroes in output
        if (base32 == '0' && leadingZeroTracker) {
            continue;
        }

        leadingZeroTracker = 0;

        printf("%c", base32);
    }

    printf("\n");
}

int main() {

    // Test code

    char binary[] = "100000010101010101010100110";

    // should print 20LAL6 for the above example
    
    printf("Binary: %s\n", binary);
    printf("Base-32: ");
    binaryToBase32(binary);

    return 0;
}