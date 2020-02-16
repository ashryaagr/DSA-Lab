// #include "recMergeSort.c"
// #include "itrMergeSort.c"
#include "mergeSort.h"
#include "string.h"
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

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
    int i=0, j=0;
    while(i<sz1 && j<sz2){
        if(Ls1[i].cgpa>Ls2[j].cgpa)
            Ls[i+j] = Ls2[j++];                                                                                                                                                                                                                                                                                                                     
        else 
            Ls[i+j] = Ls1[i++];
    }
    while(i<sz1)
            Ls[i+j] = Ls1[i++];
    while(j<sz2)
            Ls[i+j] = Ls2[j++];            
}

void readRecords(Element Ls[], int size){
    for(int i=0; i<size; i++)
        scanf("%[^,],%f\n", Ls[i].name, &Ls[i].cgpa);
}

void printArr(Element Ls[], int size){
    for(int i=0; i<size; i++)
        printf("%s : %f\n", Ls[i].name, Ls[i].cgpa);
}

int main(int argc, char * argv[]){
    
    char * token = strtok(argv[1],".");
	int noOfRecords = atoi(token);

    Element Ls[noOfRecords];
    readRecords(Ls, noOfRecords);

    struct timeval t1;
    double time_taken;
    gettimeofday(&t1, NULL);
    // Assigning values to base and top for the case of recursive mergesort
    base = (int *)&time_taken;
    top = base;

    mergeSort(Ls, noOfRecords);
    time_taken = elapsedTime(t1);
    printf("===========>Time taken by Merge sort is %f ms\n", time_taken);
    printf("===========>Space taken by Merge sort : %lld bytes \n", len_space);
    // elif(!(strcmp=="cmp")){
    //     recMergeSort
    // };
    
    // printArr(Ls, 1024);
}
