#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "credit_card.h"
#include<sys/time.h>

#define initSize 10

int * stackBase;
int * stackTop;

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

void printCard(struct CreditCard card){
    printf("%llu : %s %s , %s, %d/%d\n", 
    card.card_no, card.fname, card.lname, card.bankCode, 
    card.expMon, card.expYear);
}

struct CreditCard * doubleSize(struct CreditCard * cards, int size){
    cards = realloc(cards, 2*sizeof(struct CreditCard)*size);
    return cards;
}
//Returns 1 is 1st card is greater than 2nd else 0
int compare(struct CreditCard c1, struct CreditCard c2){
    if(c1.card_no>c2.card_no)
        return 1;
    return 0;
}

// Curr represents the index on which I am currently
void insertInOrder(struct CreditCard * cards, int curr, int size){
    int index=curr;
    struct CreditCard temp=cards[curr];
    for(int i=0; i<curr; i++)
        if(compare(cards[i], cards[curr])){
            index = i;
            break;
        }
    for(int i=curr-1; i>=index; i--){
        // printf("i: %d, curr: %d\n", i, curr);
        cards[i+1]=cards[i];
    }
    cards[index]=temp;

    return;
}

void insertionSort(struct CreditCard * cards, int curr, int size){
    
    if(curr+1==size){
        int temp;
        stackTop = &temp;
        // Subtraction is in opposite manned as stack is filled from higher to lower address
        // printf("\nSize of stack is %lld bytes\n\n", (long long)stackBase - (long long)stackTop);
        return;
    }

    insertInOrder(cards, curr, size);

    return insertionSort(cards, curr+1, size);
}


int main(int argc, char * argv[]){
    
    if (argc!=2){
        printf("Invalid Number Of Arguments. Pass one command line argument for the filename\n");\
        exit(1);
    } 

    int curSize = initSize; 
    // Allocating array spaec for initSize elements because the problem asks us to 
    struct CreditCard * cards = (struct CreditCard * )malloc(sizeof(struct CreditCard)*initSize);
    FILE * F = fopen(argv[1], "r");

    if(F==NULL){
        printf("No Such File Exists.\n");
        exit(1);
    }

    struct timeval t1;
    double time_taken;
    gettimeofday(&t1, NULL);

    char end='A'; //Random
    int i=0;
    while(1){
        if(i+1==curSize){
            cards = doubleSize(cards, curSize);
            curSize *= 2;
        }
        end = fscanf(F, "\"%llu,%[^,],%d/%d,%[^,],%[^\"]\"\n", 
            &cards[i].card_no, cards[i].bankCode, 
            &cards[i].expMon, &cards[i].expYear, cards[i].fname, cards[i].lname);
        
        if (end==EOF) break;
        // printf("%d => " , i);
        // printCard(cards[i]);
        i++;
    }

    time_taken = elapsedTime(t1);
    printf("Time taken for reading records is : %f ms\n", time_taken);

    stackBase = &curSize;
    
    gettimeofday(&t1, NULL);

    insertionSort(cards, 1, i+1);

    time_taken = elapsedTime(t1);

    printf("Number of cards is %d\n", i);
    printf("Size of the stack is %lld bytes\n",
     (long long)stackBase - (long long)stackTop);
    printf("Time taken for insertion sort is : %f ms\n\n", time_taken);

    // for(int j=0; j<i; j++){
    //     printf("%d => " , j);
    //     printCard(cards[j]);
    //     }
    
    free(cards);

    fclose(F);
}
