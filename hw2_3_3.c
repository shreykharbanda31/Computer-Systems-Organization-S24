#include <stdio.h>
#include <stdlib.h>

// Q3 3. Code for when lengths of a and b are known

// function to caclulate sequence of lex product
int* lex(int *a, int n, int *b, int m) {
  int *result = (int*)malloc(n * (m+1) * sizeof(int)); // Allocating memory for result
  int i, j, k = 0;

  for (i = 0; i < n; i++) {
    // Appending element from a
    result[k++] = a[i]; 
    for (j = 0; j < m; j++) {
      result[k++] = b[j]; // Appending b
    }
  }
  return result;
}

int main() {
  int a[] = {1, 2};
  int b[] = {3};
  // important to divide size of array by size of int value to get num of elements 
  int n = sizeof(a) / sizeof(a[0]);
  int m = sizeof(b) / sizeof(b[0]);

  int *lex_result = lex(a, n, b, m);

  printf("Lexicographic product of a and b: ");
  for (int i = 0; i < n * (m+1); i++) {
    printf("%d ", lex_result[i]);
  }
  printf("\n");

  free(lex_result); // Releasing allocated memory
  return 0;
}
