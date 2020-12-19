#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define SIZE 20

void swap(int array[SIZE], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void Selection(int array[SIZE]){
    int Min;
    int j;
    for(int i=0; i<SIZE-1; i++){
        Min = i;
        for(j=i+1; j<SIZE; j++){
            if(array[j] < array[Min]){
                Min = j;
            }
        }
        if(i != Min){
            int tmp = array[i];
            array[i] = array[Min];
            array[Min] = tmp;
        }
    }
}

int main(int argc, char *argv[]){

    int array[SIZE] = {0};

    for(int i=0; i<SIZE; i++){
        array[i] = abs(((rand()*33)%100)*rand())%97;
        /* printf("%d\n", array[i]); */
    }

    Selection(array);

    printf("====================\n");
    for(int i=0; i<SIZE; i++)
        printf("%d\n", array[i]);

    return 0;
}
