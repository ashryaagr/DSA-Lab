#include<stdlib.h>
#include "q2.h"
#include "linkedlist.h"
#include<time.h>



struct linkedList createList(int N){
    srand(time(0));
    struct linkedList * Ls = myalloc(sizeof( struct linkedList ));
    for(int i=0; i<N; i++){
        int random_no = rand();
        insertFirst(Ls, random_no);
    }
    return *Ls;
}

struct linkedList createCycle( struct linkedList Ls){
    srand(time(0));
    int toss = rand(); // 0 denotes a linear list and 1 denotes a cyclic list
    toss = toss%2;
    if(toss){
        printf("Toss won for Circular List\n");
        int r = rand();
        struct node * n = Ls.first;
        struct node * d = NULL;
        int count=0, position=rand()%Ls.count;
        while(n->next!=NULL){
            if(count++==position){
                d = n;
                break;
            }

        }
        n->next = d;
        // if(d!=NULL){
        //     printf("Found an element in list matching the random number. Creating a circular list\n");
        //     n->next = d;
        // }
        // else{
        //     printf("There is no element in list matching the randm number. So returning List as it is\n")
        // }
    }else{
        printf("Toss won for Linear List\n");
    }
    return Ls;
}
