#include <stdio.h>

/*
Define a linked list storing integers (you can use a struct to define a type ”node” with the fields val and
next).
1. In the main function, implement by hand the first three nodes storing the values 5, 3, 2.
2. Write a while loop to print the values of the linked list you just made.
3. Write a find function that takes as parameters a pointer to a node and the integer to find, and
returns a pointer to the node containing the desired value.
*/

typedef struct node {
int val;
struct node * next;
} node;

// 3
node* find_node(node* list, int n);

int main() {

    // 1
    node node3 = {2, NULL};
    node node2 = {3, &node3};
    node node1 = {5, &node2};

    // 2
    node * ptr = &node1;
    while (ptr != NULL){
        printf("%d ",  ptr -> val);
        ptr = ptr -> next;
    }
    printf("\n");

    // 3
    node* nd = find_node(&node1, 8);
    if (!(nd)) printf("Pointer not found");
    else printf("Pointer: %d", (nd)->val);
    printf("\n");
    nd = find_node(&node1, 3);
    if (!(nd)) printf("Pointer not found");
    else printf("Pointer found for: %d", (nd)->val);
    printf("\n");

    return 0;
}

node* find_node(node* list, int n){
    node* ptr = list;
    while (ptr != NULL){
        if (ptr -> val == n) {
            return ptr;
        }
        else {
            ptr = ptr -> next;
        }
    }
    return NULL;
}