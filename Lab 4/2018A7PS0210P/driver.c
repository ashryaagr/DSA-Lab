#include<stdio.h>
#include<stdlib.h>
#include "cycle.h"
#include<sys/time.h>

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

int main(int argc, char *argv []){
    // void * ptr = malloc(20);
    // printf("%u, %d", ptr, sizeof(*ptr));

    // ptr++;
    // printf("\n%u", ptr);
    if (argc!=2){
        printf("Invalid Number Of Arguments. Pass one command line argument for the number of elements in List\n");\
        exit(1);
    }
    int N = atoi(argv[1]);
    if(N<0){
        printf("Pass a non negative number as argument\n");
        exit(1);
    }
    struct timeval t1;
    double time_taken;
    gettimeofday(&t1, NULL);

    struct linkedList list = createList(N);
    // printList(&list);
    list = createCycle(list);
    int is_cycle = testCycle(list);

    time_taken = elapsedTime(t1);


    if(is_cycle){
        printf("The Linkedlist has a cycle\n");
    }else{
        printf("The linkedlist does not have a cycle\n");
    }

    printf("Total time taken is %fs ms\n", time_taken);
}
