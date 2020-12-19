#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define SIZE 20

void swap(int array[SIZE], int j){
    int tmp = array[j];
    array[j] = array[j+1];
    array[j+1] = tmp;
}

void Bubble(int array[SIZE]){
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i; j++){
            if(array[j] > array[j+1])
                swap(array, j);
        }
    }
}

int main(int argc, char *argv[]){

    int array[SIZE] = {0};

    for(int i=0; i<SIZE; i++){
        array[i] = abs(((rand()*33)%100)*rand())%97;
        printf("%d\n", array[i]);
    }
    Bubble(array);
    printf("====================\n");
    for(int i=0; i<SIZE; i++)
        printf("%d\n", array[i]);

    return 0;
}
