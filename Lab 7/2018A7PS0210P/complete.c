#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>

typedef struct Employee {
    char name[11]; // 1 extra char for null character
    int empID;
} Employee;

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

void swap(Employee* a, Employee* b) 
{ 
    Employee temp = *a;
    *a = *b; 
    *b = temp;
} 

void printArr(FILE *f, Employee arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        fprintf(f, "%d %s\n", arr[i].empID, arr[i].name);
}

int partition(Employee arr[], int l, int h) 
{ 
    Employee x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j].empID <= x.empID) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 

void quickSortIterative(Employee arr[], int low, int high, int S)
{
    int top = -1;
    // auxiliary stack
    int Stack[high - low + 1];

    Stack[++top] = low;
    Stack[++top] = high;

    while (top > -1) {
        high = Stack[top--];
        low = Stack[top--];

        if(high+1-low>S) {
            int p = partition(arr, low, high);
            if (p - 1 > low) {
                Stack[++top] = low;
                Stack[++top] = p - 1;
            }
            if (p + 1 < high) {
                Stack[++top] = p + 1;
                Stack[++top] = high;
            }
        }
    } 
} 

void insertionSortIterative(Employee * arr, int n){
    for(int i=1,j=0,k ; i<n; i++, j=0){
        while(j<i && arr[j].empID<=arr[i].empID) j++;
        Employee temp = arr[i];
        k=i-1;
        while(k>=j) {
            arr[k+1]=arr[k];
            k--;
        }
        arr[j]=temp;
    }
}

double * testRun(Employee Ls[], int size) {
    Employee copy1[size], copy2[size];
    for(int i=0; i<size; i++)
        copy1[i]=copy2[i]=Ls[i];
    struct timeval t1;
    double * times = malloc(sizeof(double)*2);
    gettimeofday(&t1, NULL);

    insertionSortIterative(copy1, size);
    times[0] = elapsedTime(t1);

    gettimeofday(&t1, NULL);
    quickSortIterative(copy2, 0, size-1, 0);
    times[1] = elapsedTime(t1);
    return times;
}

int isApproxEqual(double p, double q){
    if(p>=1.05*q || p<=0.95*q) return 1;
    return 0;
}

int estimateCutoff(Employee Ls[], int size){
    int mid, min=0, max=size-1;
    double * tt1 = testRun(Ls, min); // assert tt1.IStime < tt1.QStime
    double * tt2 = testRun(Ls, max); // assert tt1.IStime > tt1.QStime
    double * tt;
    do {
        mid =(min+max)/2;
        tt = testRun(Ls, mid);
//        printf("size : %d, InsertionSort : %f, QuickSort :%f\n", mid, tt[0], tt[1]);
        if(tt[1]>tt[0])
            min=mid;
        else
            max=mid;
    } while(isApproxEqual(tt[0],tt[1]));
    return mid;
}

// n denotes number of elements and Size demotes the cutoff size
void hybridSort(Employee * arr, int n, int Size){
    quickSortIterative(arr, 0, n-1, Size);
    insertionSortIterative(arr, n);
}

int readRecords(Employee * arr, FILE *f){
    int i=0;
    if (f == NULL){
        printf("Error! opening file. Make sure you entered correct filename");
        exit(1);
    }
    while(!feof(f)){
        fscanf(f, "%s %d\n", arr[i].name, &arr[i].empID);
        i++;
    }
    return i;
}

int main(int argc, char * argv[]) 
{ 
    if(argc!=3){
        printf("Supply valid number of arguments.\n");
        exit(1);
    }

    int N = atoi(argv[1]);

    Employee arr[N];
    FILE *f = fopen(argv[1], "r");
    FILE *op= fopen(argv[2], "w");
    int n = readRecords(arr, f);
//    insertionSortIterative(arr, n);
//    quickSortIterative(arr, 0, n - 1, 0);
    int cutOff = estimateCutoff(arr, n);

    struct timeval t1;
    gettimeofday(&t1, NULL);
    double time_taken;

    hybridSort(arr, n, cutOff);

    time_taken=elapsedTime(t1);

    fprintf(op, "Time Taken to Sort using the Hybrid Algorithm : %fms\n\n", time_taken);
    printArr(op, arr, n);
    return 0; 
} 
