
#include <stdio.h>

int main() {
    // Q2 Store n elements in an array and print them using pointers
    int arr[7] = {1,2,3,4,5,6,7};
    int *p = arr;
    while ((*p) != '\0'){
        printf("%d\t", *p);
        p++;
    }
    printf("\n");

    //Q3 Find permutations of "abcd" using pointers and swap function
    
    // Q1
    int *pt1, *pt2;
    int num1, num2;
    pt1 = &num1;
    pt2 = &num2;
    scanf("%d", pt1);
    scanf("%d", pt2);
    printf("%d", ((*pt1)+(*pt2)));
    if ((*pt1) > (*pt2)){
        printf("\n%d is larger", *pt1);}
    else {
        printf("\n%d is larger", *pt2);
    }

    return 0;
}


