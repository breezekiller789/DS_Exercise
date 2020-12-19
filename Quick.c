#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define SIZE 20

int Partition(int array[SIZE], int P, int N){
    int PK = array[N];
    int i = P-1;
    for(int j=P; j<=N; j++){
        if(array[j] < PK){
            i++;
            int tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }
    int tmp = array[i+1];
    array[i+1] = array[N];
    array[N] = tmp;
    return i+1;
}

void Quick(int array[SIZE], int P, int N){
    if(P < N){
        int q;
        q = Partition(array, P, N);
        Quick(array, P, q-1);
        Quick(array, q+1, N);
    }
}

int main(int argc, char *argv[]){

    
    int array[SIZE] = {0};

    for(int i=0; i<SIZE; i++){
        array[i] = abs(((rand()*33)%100)*rand())%97;
        /* printf("%d\n", array[i]); */
    }

    Quick(array, 0, SIZE-1);
    
    for(int i=0; i<SIZE; i++)
        printf("%d\n", array[i]);


    return 0;
}
