#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

long long array[100];
int cnt=0;

long long fib(int n){
    cnt++;
    if(array[n] != -1)
        return array[n];
    return array[n] = fib(n-1) + fib(n-2);
}

//  0 1 1 2 3

int main(int argc, char *argv[]){

    for(int i=2; i<100; i++){
        array[i] = -1;
    }
    array[0] = 0;
    array[1] = 1;
    int num;
    scanf("%d", &num);
    /* fib(num); */
    printf("%lld\n", fib(num));
    printf("%d\n", cnt);
    /* for(int i=2; i<=num; i++){ */
    /*     printf("%d\n", array[i]); */
    /* } */

    return 0;
}
