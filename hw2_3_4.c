#include <stdio.h>
#include <stdlib.h>

// Q3 4. Code for when lengths of a and b are not known

// Important since we don't know the actual capacity as len(a) and len(b) are unknown
#define INITIAL_CAPACITY 10

// returns sequence of lex product of a and b without knowing their lengths
int* lex(int *a, int *b) {
    int capacity = INITIAL_CAPACITY;
    int *result = (int*)malloc(capacity * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Iterate through elements of a
    while (a[i] != -1) {
        result[k++] = a[i++];

        // Iterate through elements of b
        j = 0;
        while (b[j] != -1) {
            if (k >= capacity) {
                capacity *= 2; // Double capacity if needed
                result = (int*)realloc(result, capacity * sizeof(int));
            }
            result[k++] = b[j++];
        }
        if (k >= capacity) {
                capacity *= 2; // Double capacity if needed
                result = (int*)realloc(result, capacity * sizeof(int));
            }
        // Adding sentinel
        result[k] = -1;
    }
    result = (int*)realloc(result, (k+1) * sizeof(int)); // Resize to actual size
    return result;
}

int main() {
    int a[] = {5, 2, 0, -1};  // Including sentinel in a
    int b[] = {3, 4, 9, 6, -1};  // Including sentinel in b

    int *lex_result = lex(a, b);
    int i = 0;
    printf("Lexicographic product of a and b: ");
    while(lex_result[i] != -1) {
        printf("%d ", lex_result[i++]);
    }
    printf("\n");

    free(lex_result);
    return 0;
}
