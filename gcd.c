#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int gcd(int m, int n){
    if(m%n == 0)
        return n;
    return gcd(n, m%n);
}

int main(int argc, char *argv[]){

    printf("%d\n", gcd(123881, 123882));

    return 0;
}
