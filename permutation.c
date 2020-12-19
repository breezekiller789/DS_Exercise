#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

char array[4] = "abc";

void swap(int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void perm(int i, int n){
    if(i==n){
        printf("%s\n", array);
    }
    else{
        for(int j=i; j<n; j++){
            swap(i, j);
            perm(i+1, n);
            swap(i, j);
        }
    }

}

int main(int argc, char *argv[]){
    perm(0, 3);

    return 0;
}
