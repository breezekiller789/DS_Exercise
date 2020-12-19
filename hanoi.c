#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int hanoi(int n, char A, char B, char C){
    if(n==1)
        printf("move %d from %c to %c\n", n, A, C);
    else{
        hanoi(n-1, A, C, B);
        printf("move %d from %c to %c\n", n, A, C);
        hanoi(n-1, B, A, C);
    }
}

int main(int argc, char *argv[]){

    int n=5;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
