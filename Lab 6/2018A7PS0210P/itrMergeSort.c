#include "merge.h"
long long len_space;
int *base, *top;

void mergeSort(Element Ls[], int size){
    int block=1;
    while(block<size){
        for(int i=0; i<size; i+=2*block){
            if(i+2*block <= size){
                // Element * Lstemp = (Element *) malloc(sizeof(Element)*2*block);
                Element Lstemp[2*block];
                merge(Ls+i, block, Ls+i+block, block, Lstemp);
                for(int j=0; j<2*block; j++)
                    Ls[i+j] = Lstemp[j];
                int x;
                if(top>&x)
                    top = &x;
                // printf("block: %d, top: %p, x:%p, Size of array : %lu\n", block, top, &x, sizeof(Element)*2*block);
            }
            else {
                int siz1 = (size-i)/2;
                // Element * Lstemp = (Element *) malloc(sizeof(Element)*(size-i));
                Element Lstemp[size-i];         
                merge(Ls+i, siz1, Ls+i+siz1, size-i-siz1, Lstemp); //Imp:=>Need to correct array pointers here
                for(int j=0; j<size-i;j++)
                    Ls[i+j] = Lstemp[j];
                int x;
                if(top>&x)
                    top = &x;
            }
        }
        block *= 2;
    }
    // printf("top: %p, base : %p\n", top, base);
    len_space = (long long)base-(long long)top;
}
