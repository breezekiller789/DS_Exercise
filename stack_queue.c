#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

int stack[20]={0};
int queue[20]={0};
int top = -1;

void push(int key){
    stack[++top] = key;
}

int pop(){
    return stack[top--];
}

int main(int argc, char *argv[]){

    for(int i=0; i<10; i++){
        int n = abs(((rand()%100+33)*rand()))%100;
        push(n);
        printf("Pushed %d\n", n);
    }
    printf("\n\n");
    for(int i=0; i<10; i++){
        printf("%d\n", pop());
    }

    

    return 0;
}
