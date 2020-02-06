#include<stdio.h>
#include<stdlib.h>

int mem=0; //Track of number of bytes allocated to the heap

int getmem(){
    return mem;
}

// num denotes the number of  bytes of space requested
void * myalloc(int num){
    mem += (num+4);
    void * ptr =  malloc(num+4);
    *(int *)ptr = num+4;
    ptr = (void *) ptr;
    if(!ptr)
        exit(1);
    return ptr+4;
}

void myfree(void * ptr){
    // free up size number of bytes starting from ptr
    ptr -=4;
    int siz = * (int *)ptr;
    mem -= (siz+4);
    // for(int i=0; i<size; i++){
        free(ptr);
    //     if(i!=size-1)ptr++;
    // }
}

void playarray(int M){
    int * A = myalloc(sizeof(int)*M);
    printf("Starting memory : %p\t Ending memory : %p\n", &A[0], &A[M-1]);
    myfree(A);
}

void q2(){
    while(1){
        int M = rand()%15001+10000;
        playarray(M);
    }
}

// int main(){
//     q2();
// }
