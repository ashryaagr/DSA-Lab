#include "merge.h"

int * base,* top;
long long len_space;

void mergeSort(Element Ls[], int size){
    if(size==1){
        int x;
        top = &x;
        len_space = (long long)base-(long long)top;
    // printf("top: %p, base : %p\n", top, base);
        return ;
    }
    int mid = (size-1)/2;
    // Separately call Recursive merge sort on 2 parts
    mergeSort(Ls, mid+1);
    mergeSort(Ls+mid+1, size-mid-1);
    Element Lstemp[size];

    int x;
    if(top>&x)
        top = &x;

    merge(Ls, mid+1, Ls+mid+1, size-mid-1, Lstemp);
    //copy back from Lstemp to Ls
    for(int i=0; i<size;i++)
        Ls[i] = Lstemp[i];
    return;
}
