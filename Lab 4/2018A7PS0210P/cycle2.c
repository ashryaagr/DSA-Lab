#include<stdio.h>
#include "q3.h"

//Link reversal
int testCycle(struct linkedList list){
    struct node *prev=list.first, *curr=list.first, *next;
    if(curr==NULL) return 0;
    else if (curr->next==curr) return 1; 
    for(;curr!=NULL&&curr->next!=NULL;){
        prev = curr;
        curr = prev ->next;
        next = curr->next;
        curr->next = prev;
        curr = next;
        if(curr==list.first)
            return 1;
    }
    return 0;
}
