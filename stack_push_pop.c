#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int isEmpty (const long *start, const long *end);
void push (long **start, long **end, long value);




void printStack(long **start, long **end) {
    printf("Stack --> [ ");
    if (!isEmpty(*start, *end)) {
        for (int i = 0; *start + i < *end; i++) {
            printf("%ld ", (*start)[i]);
        }
    } 
    printf("]\n");
}

int main () {
    printf("Starting...\n");
    long *start = NULL;
    long *stop = NULL;
    printStack(&start, &stop);
    push(&start, &stop, 1L);
    printStack(&start, &stop);
    push(&start, &stop, 2L);
    printStack(&start, &stop);
    push(&start, &stop, 3L);
    printStack(&start, &stop);
    push(&start, &stop, 4L);
    printStack(&start, &stop);
    push(&start, &stop, 5L);
    printStack(&start, &stop);
/***Expected Output:****

Starting...
Stack --> [ ]
Stack --> [ 1 ]
Stack --> [ 1 2 ]
Stack --> [ 1 2 3 ]
Stack --> [ 1 2 3 4 ]
Stack --> [ 1 2 3 4 5 ]
popped 5
Stack --> [ 1 2 3 4 ]
popped 4
Stack --> [ 1 2 3 ]
popped 3
Stack --> [ 1 2 ]
popped 2
Stack --> [ 1 ]
popped 1
Stack --> [ ]
popped 0
Stack --> [ ]

**********************/
    
}

int isEmpty (const long *start, const long *end){
    if (&start==&end){
        return 1;
    }
    if (start==NULL||end==NULL){
        return 1;
    }
    else{
        return 0;
    }
}


void push (long **start, long **end, long value){ 
    if (isEmpty(*start,*end)==1){
        long*crazy = (long*)malloc((1)*sizeof(long)); 
        crazy[0]=value;
        *start = &crazy[0];
        *end = &crazy[1];
    }
    else{
        int counter = 0;
        int i = 0;
            for (int i = 0; *start + i < *end; i++){ 
                counter++;
            }
        long*crazy = (long*)malloc((counter+1)*sizeof(long)); 
        for (int i = 0; *start + i < *end; i++) {
            crazy[i]=(*start)[i];        
            }
        crazy[counter]=value;
        *start = &crazy[0];
        *end = &crazy[counter+1];
    }
}
    


