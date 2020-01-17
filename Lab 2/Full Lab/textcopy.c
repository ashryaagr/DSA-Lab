#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char *argv[]){
    printf("You want to copy data from %s to %s\n", argv[1], argv[2]);
    FILE* readfile = fopen(argv[1], "r");
    FILE* writefile= fopen(argv[2], "w");
    if (readfile==NULL){
        printf("%s file does not exist\n", argv[1]);
        // exit(0);
    }
    char c = fgetc(readfile);
    while(c!=EOF){
        fputc(c, writefile);
        c = fgetc(readfile);
    }
    fclose(readfile);
    fclose(writefile);
}