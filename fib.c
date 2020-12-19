#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

long long fib(int n){
    if(n==0 || n==1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}

int main(int argc, char *argv[]){

    int num;
    scanf("%d", &num);
    printf("%lld\n", fib(num));

    return 0;
}
