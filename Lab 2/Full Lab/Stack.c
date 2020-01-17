#include <stdlib.h>
#include "Stack.h"

int pop(struct Stack * s){
    int head = s->head;
    struct linkedList *l = s->list;
    if (l->count==0)
        return -9999;

    deleteFirst(l);

    if(l->count>0){
        struct node *h = l->first;
        s->head = h->element;
    } else {
        s->head = -9999;
    }
    return head;
}

void push(struct Stack * s, int e){
    struct linkedList *l = s->list;

    insertFirst(l, e);
    s->head = e;
}
