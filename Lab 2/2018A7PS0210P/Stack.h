# include <stdio.h>
#include "linkedlist.h"

struct Stack {
    int head;
    struct linkedList * list; 
};

void push(struct Stack * s, int e);

int pop(struct Stack * s);
