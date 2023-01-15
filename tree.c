#include<stdio.h>
#include <stdlib.h>

struct node{
 struct node*left;
 struct node*right;
 char data;
};

struct node* insert(char c[],int n){ 
    struct node* tree=NULL;
    if(c[n]!='\0'){
        tree=(struct node*)malloc(sizeof(struct node));
        tree->left=insert(c,2*n+1);
        tree->data=c[n];
        tree->right=insert(c,2*n+2);
    }
    return tree;
}

void inorder(struct node* tree)
{
    if(tree!=NULL){
        inorder(tree->left);
        printf("%c\t",tree->data);
        inorder(tree->right);
    }
}
void preorder(struct node* tree){
    if(tree!=NULL){
        printf("%c\t",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void main(){
    struct node* tree=NULL;
    char c[]={'A','B','C','D','E','F','\0','G','\0','\0','\0','\0','H','I','\0','\0','\0','\0','J','\0','\0'};
    tree=insert(c,0);
    printf("\nThe inorder sequence is:\n");
    inorder(tree);
    printf("\nThe preorder sequence is:\n");
    preorder(tree);
}