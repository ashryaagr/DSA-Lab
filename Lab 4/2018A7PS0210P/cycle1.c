#include<stdio.h>
#include "q3.h"

int testCycle(struct linkedList L){
    struct node *tort=L.first, *hare=L.first->next;
    if(hare->next==hare) return 1;
    for(; hare!=NULL&&hare->next!=NULL&&hare->next->next!=NULL; hare=hare->next->next, tort=tort->next){
        if(hare==tort) return 1;
    }
    return 0;
}
