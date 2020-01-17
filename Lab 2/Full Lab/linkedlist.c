/* linkedlist.c */
#include "linkedlist.h"
#include<stdlib.h>

void insertFirst(struct linkedList * head, int ele){
    //create a node
    struct node *link = (struct node*) malloc (sizeof(struct node)); /* by this
    you are creating a node whose address is being stored in the link pointer. */
    link->element = ele;
    //point it to old first node
    link->next = head->first;
    //point first to new first node
    head -> first = link;
    head -> count ++; // Made a correction here
}
    //delete first item
struct node* deleteFirst(struct linkedList * head){
    // exercise to implement this operation.
    struct node* first = head->first ;
    head->first = first->next;
    head->count--;
    printf("Count of elements : %d, ", head->count);
    return first ;
}

//display the list
void printList(struct linkedList * head){
    struct node* ptr = head->first;
    printf("\n[ ");
    //start from the beginning
    while(ptr != NULL){
    printf("%d, ", ptr->element);
    ptr = ptr->next;
    }
    printf(" ]");
}

/* searches for a given element in the linked list. Returns 1 if found, 0
otherwise. */
int search (struct linkedList * head, int ele){
    struct node* curr = head->first;
    for(int i=head->count; i>0; i--){
        if(curr->element==ele)
        return 1;
        curr = curr->next;
    }
    return 0;
}

/* deletes the first node in the list that contains the element = ele and retuns it.  
If the element is not found it returns an error message saying element not found. */
struct node * delete (struct linkedList * head, int ele){
    struct node* curr = head->first;
    if(head->count==0){
        printf("List is empty :( \n");
        return NULL;
    }
    if(head->first->element==ele)
        return deleteFirst(head);
    if(head->count==1){
        printf("Element %d not found in the list :( \n", ele);
        return NULL;        
    }
    struct node* prev = curr;
    curr = prev->next;
    for(int i=head->count-1; i>0; i--){
        if(curr->element==ele){
            prev->next = curr->next;
            head->count--;
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Element %d not found in the list :( \n", ele);
    return NULL;
}
