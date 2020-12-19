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

void Insertion(int array[SIZE]){
    for(int i=1; i<SIZE; i++){
        int key = array[i];
        for(int j=i-1; j>=0; j--){
            if(key < array[j]){
                array[j+1] = array[j];
            }
            else{
                array[j+1] = key;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]){

    int array[SIZE] = {0};

    for(int i=0; i<SIZE; i++){
        array[i] = abs(((rand()*33)%100)*rand())%97;
        /* printf("%d\n", array[i]); */
    }
    Insertion(array);
    printf("====================\n");
    for(int i=0; i<SIZE; i++)
        printf("%d\n", array[i]);

    return 0;
}
