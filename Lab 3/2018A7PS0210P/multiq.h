#include<stdio.h>

#include"que.h"

typedef struct Priority{
    int priority;
} Priority;

typedef struct Task{
    int taskid;
    Priority priority;
} Task;

typedef struct MultiQ{
    Queue * q;
    // Assuming that array index denotes priority
    int length;
} MultiQ;

Task cast(Element e, int Priority);

MultiQ createMQ(int num);// creates a list of num Queues each of which is empty
MultiQ addMQ(MultiQ mq, Task t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p
Task nextMQ(MultiQ mq); // returns the front of the non-empty Queue in mq with the highest priority
MultiQ delNextMQ(MultiQ mq); // deletes the front of the non-empty Queue in mq with the highest priority returns the modified MultiQ
int isEmptyMQ(MultiQ mq); // tests whether all the Queues in mq are empty
int sizeMQ(MultiQ mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(MultiQ mq, Priority p); //returns the number of items in mq with the priority p 
Queue getQueueFromMQ(MultiQ mq, Priority p);// returns the Queue with priority p
