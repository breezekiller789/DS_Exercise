#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int sum(int n){
    if(n==1)
        return 1;
    else
        return n + sum(n-1);
}

int per(int m, int n){
    if(n == 0 || m == n)
        return 1;
    else
        return per(m-1, n) + per(m-1, n-1);

}

int main(int argc, char *argv[]){

    int n = 2;
    int m = 10;
    printf("%d\n", per(m, n));

    return 0;
}
