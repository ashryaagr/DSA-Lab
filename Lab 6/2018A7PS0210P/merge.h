#include<stdio.h>
#include<stdlib.h>
#ifndef MERGE_H
#define MERGE_H

typedef struct Element{
    char name[11];
    float cgpa;
} Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);

#endif