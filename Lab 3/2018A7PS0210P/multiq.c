#include<stdlib.h>
#include"multiq.h"


Task cast(Element e, int priority){
    Task t;
    t.taskid = e.element;
    t.priority.priority = priority;
    return t;
}

MultiQ createMQ(int num){
    MultiQ mq;
    mq.length = num;
    mq.q = malloc(num*sizeof(Queue));
    for(int i=0; i<num; i++){
        mq.q[i].head = mq.q[i].tail = NULL;
        mq.q[i].count =0;
    }
    return mq;
} // creates a list of num Queues each of which is empty

MultiQ addMQ(MultiQ mq, Task t) {
    Element e;
    e.element = t.taskid;
    mq.q[t.priority.priority -1] = addQ(mq.q[t.priority.priority-1], e);
    return mq;
    }// adds t to the Queue corresponding to priority p in mq Task includes a TaskID tid and a priority p

Task nextMQ(MultiQ mq){
    for(int i=mq.length-1; i>=0; i--){
        if(mq.q[i].count!=0){
            return cast(front(mq.q[i]), i+1);
        }
    }
    // If all que are empty, then we return a task which doesn't correspond to any valid taskid or priority
    Element e ;
    e.element = -9999;
    return cast(e, -9999);
} // returns the front of the non-empty Queue in mq with the highest priority

MultiQ delNextMQ(MultiQ mq){
    for(int i=mq.length-1; i>=0; i--){
        if(mq.q[i].count!=0){
            Task t = nextMQ(mq);
            mq.q[i] = delQ(mq.q[i]);
            return mq;
        }
    }
    return mq;    
} // deletes the front of the non-empty Queue in mq with the highest priority returns the modified MultiQ

int isEmptyMQ(MultiQ mq){
    for(int i=0; i<mq.length; i++)
        if(mq.q[i].count!=0)
            return 0;
    return 1;
} // tests whether all the Queues in mq are empty

int sizeMQ(MultiQ mq){
    int sum=0;
    for(int i=0; i<mq.length; i++){
        sum+= mq.q[i].count;
    }
    return sum;
} // returns the total number of items in the MultiQ

int sizeMQbyPriority(MultiQ mq, Priority p) {
    return mq.q[p.priority-1].count;
    }//returns the number of items in mq with the priority p Queue

Queue getQueueFromMQ(MultiQ mq, Priority p) {
    return mq.q[p.priority-1];
}//returns the Queue with priority p
