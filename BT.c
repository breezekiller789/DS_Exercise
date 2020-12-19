#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define MaxLine 1024
#define COUNT 8 
#define TRUE 1
#define FALSE 0

struct BT{
    int data;
    struct BT *left;
    struct BT *right;
};

void inorder(struct BT *root){
    if(root == NULL)
        return ;
    else{
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

void preorder(struct BT *root){
    if(root==NULL)
        return;
    else{
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct BT *root){
    if(root==NULL)
        return;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}

// Function to print binary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(struct BT *root, int space) 
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
void print2D(struct BT *root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
} 

void swap(struct BT *root){
    if(root==NULL){
        return;
    }
    else{
        swap(root->left);
        swap(root->right);
        struct BT *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

}

int Count(struct BT *root){
    if(root == NULL){
        return 0;
    }
    else{
        int nl = Count(root->left);
        int nr = Count(root->right);
        return nl + nr + 1;
    }
}

struct BT *Copy(struct BT *root){
    if(root==NULL){
        return NULL;
    }
    else{
        struct BT *T = (struct BT *)malloc(sizeof(struct BT));
        T->data = root->data;
        T->left = Copy(root->left);
        T->right = Copy(root->right);
        return T;
    }
}

int Leaf(struct BT *root){
    if(!root)
        return 0;
    else{
        int nl = Leaf(root->left);
        int nr = Leaf(root->right);
        if(nl==0 && nr==0)
            return 1;
        return nl + nr;
    }

}

int Equal(struct BT *root, struct BT *New){
    if(!root && !New){
        return TRUE;
    }
    else if(root && New){
        if(root->data == New->data){
            if(Equal(root->left, New->left)){
                return Equal(root->right, New->right);
            }
        }
    }
    return FALSE;
}

int Height(struct BT *root){
    if(!root)
        return 0;
    else{
        int HL = Height(root->left);
        int HR = Height(root->right);
        if(HL > HR)
            return HL + 1;
        else
            return HR + 1;
    }
}

int main(int argc, char *argv[]){

    struct BT *array[10];
    for(int i=1; i<10; i++){
        array[i] = (struct BT *)malloc(sizeof(struct BT));
    }
    int cnt = 0;
    for(int i=4; i>=1; i--){
        array[2*i]->data = (rand() % 100) +1;
        array[2*i+1]->data = (rand() % 100) +1;
        array[i]->left = array[2*i];
        array[i]->right = array[2*i+1];
    }
    print2D(array[1]);
    struct BT *New = Copy(array[1]);
    swap(New);
    printf("Equal = %d\n", Equal(array[1], New));
    printf("Leaf = %d\n", Leaf(array[1]));
    printf("Height = %d\n", Height(array[1]));
    return 0;
}
