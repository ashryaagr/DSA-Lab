#include<stdio.h>
#include<stdlib.h>
#define maxname 20
struct CreditCard{
    unsigned long long card_no;
    char bankCode[5];
    char fname[maxname];
    char lname[maxname];
    int expMon;
    int expYear;
};