#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* insert(struct node* head,int data){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    if(head==NULL)
        head=p;
    else{
        struct node* temp;
        temp=head;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=p;
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
            temp=temp->link;
        }
    }
}
struct node* reverse(struct node* head){
    struct node* prev=NULL;
    struct node* next=NULL;
    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    
    return head;
}
void main(){
    struct node* head=NULL;
    struct node* rev=NULL;
    int data,n,i;
    printf("Enter the limit: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the data: ");
        scanf("%d",&data);
        head=insert(head,data);
        
    }
    display(head);
    rev=reverse(head);
    printf("\nReverse list is:\n");
    display(rev);
}