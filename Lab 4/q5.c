#include<stdio.h>
#include "q3.h"
#include"cycle.h"

struct linkedlist makeCircularList(struct linkedlist Ls){
    if(!testCycle(Ls)){
        struct node* curr=Ls.first; 
        while(curr->next!=NULL)
            curr = curr->next;
        curr->next = Ls.first;
        return Ls;
    }else {
        if(hare->next==hare) return Ls; // Only 1 element present
        for(; hare!=NULL&&hare->next!=NULL; hare=hare->next->next, tort=tort->next)
            if(hare==tort) break;
        tort = Ls.first;
        for(;; hare=hare->next, tort=tort->next)
            if(hare==tort) break;
        // Now hare has the position of the starting of the loop
        while(hare!=Ls.first)
            deleteFirst(Ls);
        return Ls;
    }
}