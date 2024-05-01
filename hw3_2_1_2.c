#include <stdio.h>

typedef struct node {
long id;
char * name;
struct node * next;
} node;


char* mystery(node *n, long id){
    while (n != NULL){          // L1
        if (id == n -> id){     // L3
            return n->name;
        } 
        n = n -> next;          // L2
    }
    return NULL;
}

int main(){

    // Testing my code
    node node3 = {2, "cso", NULL};
    node node2 = {3, "hw", &node3};
    node node1 = {5, "cool", &node2};
    char* nd = mystery(&node1, 5);
    if (!(nd)) printf("Name not found");
    else printf("Name: %s", nd);
    printf("\n");
    nd = mystery(&node1, 10);
    if (!(nd)) printf("Name not found");
    else printf("Name: %s", nd);
    printf("\n");
    return 0;
}