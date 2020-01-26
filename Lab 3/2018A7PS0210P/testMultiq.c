// The program expects 2 command line arguments : filename and the number of elements to delete

#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h> // for gettimeofday()
#include"multiq.h"
#define MQ_MAX 10


MultiQ loadData(FILE *f){
    int task_id, priority;
    MultiQ mq = createMQ(MQ_MAX);
    Task t;
    while(1){
        if(feof(f))
            break;
        fscanf(f, "%d,%d ", &task_id, &priority);
        t.taskid = task_id;
        t.priority.priority = priority;  
        mq = addMQ(mq, t);    
    }
    return mq;
}// reads from f a list of pairs (task_id, priority) and adds each item to a MultiQ appropriately

MultiQ testDel(MultiQ mq, int num){
        for(int i=0; i<num; i++){
            mq = delNextMQ(mq);
        }
        return mq;
}//MultiQ testDel(int num) – performs num of delNextMQ operations

double elapsedTime(struct timeval t1){
    // t1 is the start time of timer
    struct timeval t2;
    double elapsedTime;
    // stop timer
    gettimeofday(&t2, NULL);
    // compute and print the elapsed time in millisec
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    return elapsedTime;

}

// The program expects 2 command line arguments : filename and the number of elements to delete
int main(int argc, char * argv[]){
    if(argc!=3){
        printf("Please enter aruguments in proper format : ./exe filename Number_of_elements_to_delete");
        exit(1);
    }
    struct timeval t1;
    double time_taken;
    // start timer
    // Need to compute average delete operation time abd see the positioning of timings inside loaddata
    // Also specify somewhere that the program requires 2 arguments, one for filename and one for the number of elements you want to insert
    FILE * f = fopen(argv[1], "r");

    if (f == NULL){
        printf("Error! opening file. Make sure you entered correct filename");
        exit(1);
}
    gettimeofday(&t1, NULL);
    MultiQ mq = loadData(f);
    time_taken = elapsedTime(t1);

    printf("Time taken for adding the elements to MultiQ within the loadData operation : %f ms.\n", time_taken);
    fclose(f);

    int no_of_elements_delete = atoi(argv[2]);

    if(no_of_elements_delete>sizeMQ(mq)){
        printf("Can't delete more elements than the input elements. Please enter valid second argument.\n");
        no_of_elements_delete = sizeMQ(mq);

    }

    gettimeofday(&t1, NULL);
    mq = testDel(mq, no_of_elements_delete);
    time_taken = elapsedTime(t1)/no_of_elements_delete;
    printf("The average cost per delete operation : %f ms.\n", time_taken);
}
