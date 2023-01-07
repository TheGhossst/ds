//Binary Search Tree With Post/In/Pre Order Traversals
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node* root,int data){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}
void preorder(struct node* tree){
    if(tree==NULL)
        return;
    printf("%d\t",tree->data);
    preorder(tree->left);
    preorder(tree->right);
}
void inorder(struct node *tree){
    if (tree == NULL)
        return;
    inorder(tree->left);
    printf("%d\t", tree->data);
    inorder(tree->right);   
}
void postorder(struct node *tree){
    if (tree == NULL)
       return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d\t",tree->data);
}
void main(){
    struct node* tree=NULL;
    int c,data;
    /*tree=insert(tree,20);
    tree=insert(tree,10);
    tree=insert(tree,30);
    tree=insert(tree,40);*/
    printf("\n..............................\n");
    printf("1.Insert Elements\n2.Preorder Sequence\n3.Inorder Sequence\n4.Postorder sequence\n5.Exit");
    printf("\n................................\n");
    do{
        printf("\nEnter a choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("\nEnter element to be inserted in the tree: ");
                scanf("%d",&data);
                tree=insert(tree,data);
                break;
            case 2:
                printf("\nThe preorder sequence is:\n");
                preorder(tree);
                break;
            case 3:
                printf("\nThe preorder sequence is:\n");
                preorder(tree);
                break;
            case 4:
                printf("\nThe postorder sequence is:\n");
                postorder(tree);
                break;
            case 5:
                printf("\nExiting\n");
                break;
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }while(c!=5);
    
}
