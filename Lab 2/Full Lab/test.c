/* File: test.c */
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int isNumber( char *, int );
int main(int argc, char *argv[])
{
    for(int i=0; i<argc ; i++){
        if(isNumber(argv[i], sizeof(argv[i]))){
            int x = atoi(argv[i]);
            printf("%d", x);
        } else {
            printf("%s ", argv[i]);
        }
    }

}

int isNumber(char * S, int size){
    for(int i=0; i<size; i++){
        if(!isdigit(S[i]))
            return 0;
    }
    return 1;
}
// Ans Part 1a> argc will be 3