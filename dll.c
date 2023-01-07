#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node* before;
    int data;
    struct node* next;
};
struct node* insert(struct node* head,int item){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=item;
    p->next=NULL;
    p->before=NULL;
    if(head==NULL)
        head=p;
    else{
        struct node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        p->before=temp;
        temp->next=p;
    }
    return head;
}
void display(struct node*head){
    if(head==NULL)
        printf("Empty List");
    else{
        struct node* temp;
        temp=head;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void rev(struct node* head){
    if(head==NULL)
        printf("Empty List");
    else{
        struct node* temp;
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        //printf("%d",temp->data);
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->before;
        }
        
    }
}
void main(){
    struct node* head=NULL;
    int n,i,item;
    printf("Enter the limit: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter data: ");
        scanf("%d",&item);
        head=insert(head,item);
    }
    printf("\nThe list is:\n");
    display(head);
    printf("\nThe reverse is:\n");
    rev(head);
}