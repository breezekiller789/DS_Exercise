#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int expo(int x, int y){
    if(y==0)
        return 1;
    else{
        return x * expo(x, y-1);
    }
}

int main(int argc, char *argv[]){

    for(int i=0; i<20; i++){
        printf("%d\n", expo(2, i));   
    }

    return 0;
}
