#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024

struct Node{
    int data;
    struct Node *next;
};

struct Node *NewNode(){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->next = NULL;
    return node;
}

void Insert(struct Node *head, int data){
    if(!head->next){
        struct Node *node = NewNode();
        node->data = data;
        head->next = node;
    }
    else{
        struct Node *node = NewNode();
        node->data = data;
        node->next = head->next;
        head->next = node;
    }
}

struct Node *Reverse(struct Node *head){
    struct Node *p, *q, *r;
    q = NULL;
    p = head;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    q->next = r;
    return q;
}

int main(int argc, char *argv[]){
    struct Node *head = NewNode();
    for(int i=0; i<10; i++){
        int n = abs(((rand()%100+33)*rand()))%100;
        Insert(head, n);
        /* printf("Insert %d\n", n); */
    }
    struct Node *node = head->next;
    while(node){
        printf("%d\n", node->data);
        node = node->next;
    }
    node = Reverse(head->next);
    printf("\n\n");
    while(node){
        printf("%d\n", node->data);
        node = node->next;
    }
    

    return 0;
}
