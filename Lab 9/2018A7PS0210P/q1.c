#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100 // Maximum size of a word
#define INIT_Size 1000 // Inital size of book array

int hash(char *s, int base, int tableSize){
    // (((sum of ASCII values of characters in string) mod baseNumber) mod tableSize)
    int sum=0;
    for(int i=0; i<strlen(s); i++)
        sum += s[i];
//    printf("sum=%d, inner=%d, ans=%d", sum, (sum%base), (sum%base)%tableSize);
    int hashVal = sum%base;
    hashVal = hashVal%tableSize;
    return hashVal;
}

int collision(char **book, int noOfWords, int base, int tableSize){
    int coll=0; // Number of collisions
    int table[tableSize];
    for(int i=0; i<tableSize; i++)
        table[i]=0;
    for(int i=0; i<noOfWords; i++){
        int k = hash(book[i], base, tableSize);
//        printf("Word=%s, hash=%d\n", book[i], k);
        if(table[k])
            coll++;
        else
            table[k]=1;
    };
    return coll;
}

//utility function
int isValidString(char* s){
    for(int i=0; i<strlen(s); i++)
        if(!((s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
            return 0;
    return 1;
}

char **parser (char fname[], int *noOfWords, int *capacity){
    int validStrings = 0;
    int noOfStrings= INIT_Size;
    FILE *f = fopen(fname, "r");
    char** book = (char **)malloc(sizeof(char *)*noOfStrings);
    if(f==NULL){
        printf("Error in Reading file. Make sure the file exists.\n");
        exit(1);
    }
    char temp[MAX];
    while(!feof(f)){
        if(validStrings >= noOfStrings){
            noOfStrings *=2;
            book = (char **)realloc(book, sizeof(char *)*noOfStrings);
        }
        fscanf(f, "%s", temp);
        if(isValidString(temp)) {
            book[validStrings] = (char *)malloc((strlen(temp)+1)* sizeof(char));;
            strcpy(book[validStrings], temp);
            validStrings++;
        }
    }
    *noOfWords = validStrings;
    *capacity = noOfStrings;
    fclose(f);
    return book;
}

//Utility function
int isPrime(int N){
    for(int i=2; i<=N/2; i++)
        if(N%i==0)
            return 0;
    return 1;
}

// utility function
int* primeNos(int tableSize){
    int* Nos = (int *)malloc(sizeof(int)*6);
    int j=0;
    for(int i=tableSize; i<=2*tableSize && j<3; i++)
        if(isPrime(i))
            Nos[j++]=i;
    for(int i=1000*tableSize; j<6 ; i++)
        if(isPrime(i))
            Nos[j++]=i;
    return Nos;
}

void freeBook(char ** book, int capacity){
    for(int i=0; i<capacity; i++)
        free(book[i]);
    free(book);
}

void profiler(char fname[]){
    int noOfWords=0, capacity=INIT_Size;
    char **book = parser(fname, &noOfWords, &capacity);
    printf("Total Number of Valid strings : %d\n", noOfWords);
    int tableSizes[] = {5000, 50000, 500000};
    int bestI, bestJ, minColl=-1;
    for(int i=0; i<sizeof(tableSizes)/sizeof(int); i++){
        int *bases = primeNos(tableSizes[i]);
        for(int j=0; j<6; j++){
            int coll=collision(book, noOfWords, bases[j], tableSizes[i]);
            if(minColl==-1 || coll>minColl){
                 bestI=i;
                 bestJ=j;
                 minColl=coll;
            }
            printf("Index => i=%d, j=%d\ntableSize=%d, baseNumber=%d\nCollision Value=%d\n\n",
                                i, j, tableSizes[i], bases[j], coll);
        }
    }
    printf("\n\nBest Parameters => i=%d, j=%d\nBest Collision Value=%d\n\n", bestI, bestJ, minColl);
    freeBook(book, capacity);
}

int main(int argc, char * argv[]){
    char *fname;
    if(argc!=2) {
        printf("As filename is not specified in arguments, default filename is used.\n");
        fname="aliceinwonderland.txt";
    } else 
        fname = argv[1]; //copy string pointer
    profiler(fname);
}
