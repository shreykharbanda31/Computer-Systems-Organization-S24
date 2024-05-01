#include <stdio.h>
#include <stdlib.h> // For malloc

typedef struct node {
int val;
struct node * next;
} node;

 // insert val in the front of the linked list
 // returns new head
void insert_front(node ** headdp, int val) {
//
// WRITE YOUR CODE HERE
node * newp =  (node*)malloc(sizeof(node));
newp->val=val;
newp->next=(*headdp);
(*headdp) = newp;
//
}

int main () {
node * headp = NULL ; // Initially, the list is empty
// Insert elements at the front of the list
for (int i = 0; i < 3; i ++) {
insert_front(&headp, i);
}

// Print the list to verify
//
node* curr = headp;
while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr -> next;
}
printf("\n");
//
//

// Free the allocated memory

node* ptr = headp;
while (ptr != NULL) {
    node* temp = ptr -> next;
    free(ptr);
    ptr = temp;
}
headp = NULL;
return 0;
}