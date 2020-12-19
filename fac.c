#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int fac(int n){
    if(n==1)
        return 1;
    else{
        return n * fac(n-1);
    }
}

int main(int argc, char *argv[]){

    int n = 5;
    printf("%d\n", fac(n));

    return 0;
}
