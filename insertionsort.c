#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size);

int main () {
    int x[]={548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    printf("%d",insertionsort(x,14));
    return 0;
}

int insertionsort(int* x, int size){
    int counter=0;
    int t;
    for (int i=0; i<size-1;i++){
        for(int j=i+1; j>0;j--){
            counter+=1;
            if (x[j]<x[j-1]){
                t=x[j-1];
                x[j-1]=x[j];
                x[j]=t;
            }
            else {
                break;
            }
        }
    }
    return counter;
}