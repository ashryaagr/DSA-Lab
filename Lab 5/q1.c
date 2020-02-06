#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "credit_card.h"

#define initSize 10

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
void insertOrder(struct CreditCard * cards, int curr, int size){
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
    if(curr+1==size){
        return cards;
    }
    return insertOrder(cards, curr+1, size);
}

int main(int argc, char * argv[]){
    
    int curSize = initSize; 
    // Allocating array spaec for initSize elements because the problem asks us to 
    struct CreditCard * cards = (struct CreditCard * )malloc(sizeof(struct CreditCard)*initSize);
    FILE * F = fopen(argv[1], "r");
    char end='A'; //Random
    int i=0;
    while(end!=EOF){
        if(i==curSize){
            cards = doubleSize(cards, curSize);
            curSize *= 2;
        }
        end = fscanf(F, "\"%llu,%[^,],%d/%d,%[^,],%[^\"]\"\n", 
            &cards[i].card_no, cards[i].bankCode, 
            &cards[i].expMon, &cards[i].expYear, cards[i].fname, cards[i].lname);
        printf("%llu\n", cards[i].card_no);
        i++;
    }

    insertOrder(cards, 0, i+1);
    
    for(int j=0; j<i; j++)
        printf("%llu\n", cards[j].card_no);
    int testVar;
    printf("Stack Space Used : %ld, 1st : %p, 2nd : %p\n", &curSize-&testVar, &curSize, &testVar);
}