#include <stdio.h>
#include <assert.h>
#include <math.h>


int binsearch(int* x, int y, int size);

int main () {
    
    int x[]=  {100};
    int size = sizeof(x)/sizeof(x[0]);
    printf("%d", binsearch(x,100,size));
    return 0;
}

int binsearch(int* x, int y, int size){
    int counter=0;
    int a=0;
    int b=size-1;
    while (1) {
            int m = floor((a+b)/2);
            counter+=1;
            if ((x[b]==y) || (x[a]==y) || (x[m]==y)){
                return counter;
            }
            else if (x[m]<y){
                a=floor((a+b)/2)+1;
            }
            else if (x[m]>y){
                b=floor((a+b)/2)-1;
            }
            if (a==b){
                return (-1);
            }
            }
        }
    
        

