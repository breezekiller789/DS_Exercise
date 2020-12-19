#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define SIZE 10
#define COUNT 10

struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};

void Heapify(int array[SIZE], int i, int n){
    int X = array[i];
    int j = 2 * i;
    while(j<=n){
        if(array[j] < array[j+1]){
            j = j+1;
        }

        //  Now j is pointing to the max

        if(X > array[j])
            break;
        else{
            array[j/2] = array[j];
            j *= 2;
        }
    }
    array[j/2] = X;
}

void BottomUp(int array[SIZE]){
    for(int i=SIZE/2; i>=1; i--){
        Heapify(array, i, SIZE-1);
    }
}

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct Tree *root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
        
    // Increase distance between levels 
    space += COUNT; 
        
    // Process right child first 
    print2DUtil(root->right, space); 
    
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
            
    // Process left child 
    print2DUtil(root->left, space); 
}
    
// Wrapper over print2DUtil() 
void print2D(struct Tree *root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
}

int main(int argc, char *argv[]){

    struct Tree *Heap[SIZE];
    struct Tree *Heap2[SIZE];
    int array[SIZE] = {0};

    //  Initialize the Heap structures
    for(int i=1; i<=SIZE; i++){
        Heap[i] = (struct Tree *)malloc(sizeof(struct Tree));
        Heap2[i] = (struct Tree *)malloc(sizeof(struct Tree));
    }

    for(int i=1; i<=sizeof(array)/sizeof(int); i++){
        array[i] = (abs((rand()%97+33)*rand()))%97;
        printf("%d\n", array[i]);
    }

    //  Before BottomUp Heap Creation
    for(int i=SIZE/2; i>=1; i--){
        if(2*i+1 >= SIZE)
            continue;
        Heap[2*i]->data = array[2*i];
        Heap[2*i+1]->data = array[2*i+1];
        Heap[i]->left = Heap[2*i];
        Heap[i]->right = Heap[2*i+1];
    }
    Heap[1]->data = array[1];

    print2D(Heap[1]);


    BottomUp(array);

    for(int i=SIZE/2; i>=1; i--){
        if(2*i+1 >= SIZE)
            continue;
        Heap[2*i]->data = array[2*i];
        Heap[2*i+1]->data = array[2*i+1];
        Heap[i]->left = Heap[2*i];
        Heap[i]->right = Heap[2*i+1];
    }
    Heap[1]->data = array[1];

    print2D(Heap[1]);



    return 0;
}
