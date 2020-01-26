#include<stdio.h>
#include<stdlib.h>
#include"que.h"

Queue newQ(){
    Queue q ;
    q.count=0;
    return q;
    
} // returns an empty Queue
int isEmptyQ(Queue q){
    return q.count;
} // tests whether q is empty

Queue delQ(Queue q){
    int count = q.count;
    if(count==0)
        return q;
    else if(count==1){
        q.count--;
        free(q.head);
        q.head = q.tail = NULL;
        return q;
    }
    Element* node = q.head;
    q.head = node->next;
    q.count--;
    free(node);
    return q;
} // deletes the element from the front of the Queue; returns the modified Queue

Element front(Queue q){
    Element * node = q.head;
    return *node;
} // returns the element from the front of the Queue;

Queue addQ(Queue q , Element e){
    // Check for the acse when queue is empty;
    Element * tail = q.tail;
    Element * newnode = malloc(sizeof(Element));
    newnode->next = NULL;
    newnode->element = e.element;
    if(q.count==0){
        q.head = newnode;
    } else{
        tail->next = newnode;
    }
    q.tail = newnode;
    q.count++;
    return q;
} // adds e to the rear of the Queue; returns the modified Queue

int lengthQ(Queue q){
    return q.count;
} // returns the length of the Queue
