#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    // Create a file pointer and open the file read as command line argument.
FILE * fileptr = fopen(argv[1], "r");
// Declare a pointer to a linked list (head) and allocate memory to it.
struct Stack * s = (struct Stack *) malloc (sizeof(struct Stack));
s->list = (struct linkedList *) malloc (sizeof(struct linkedList));

printf("\n");

// In a loop read the file and insert elements into the linkedList.
while (!feof(fileptr))
{
    // read the next element and store into the temp variable.
    int temp;
    fscanf(fileptr, "%d ", &temp);
    // insert temp into the linked list.
    push(s, temp);
    printf("Pushed %d into the stack\n", temp);
}
// close the file pointer
fclose(fileptr);
struct linkedList * list = s->list;

printf("\nList after pushing all elements:\n");
printList(list);

printf("\n\nPopping out all the elements\n");
int c;

for(int i=list->count; i>0; i--){
    printf("Popped %d out of the stack \n",pop(s));
}

printf("\n\nFinal Stack after popping out: ");
printList(list);
printf("\n");

}
