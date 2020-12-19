#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int ack(int m, int n){
    if(m==0)
        return n+1;
    if(n==0)
        return ack(m-1, 1);
    else
        return ack(m-1, ack(m, n-1));
}

int main(int argc, char *argv[]){

    printf("%d\n", ack(2, 4));

    return 0;
}
