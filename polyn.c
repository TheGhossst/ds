#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff;
    int expo;
    struct node* link;
};
struct node* insert(struct node* head,int coe,int exp){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    p->coeff=coe;
    p->expo=exp;
    p->link=NULL;
    if(head==NULL || exp>head->expo){
        p->link=head;
        head=p;
    }
    else{
        temp=head;
        while(temp->link!=NULL && exp<=temp->link->expo)
            temp=temp->link;
        p->link=temp->link;
        temp->link=p;
    }
    return head;

}
struct node* cre(struct node* head){
    int n,i,coe,exp,c1,e1;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the coefficent: ");
        scanf("%d",&coe);
        printf("Enter the exponent: ");
        scanf("%d",&exp);
        head=insert(head,coe,exp);
    }
   
    return head;
}

void display(struct node* head){
    if(head==NULL)
        printf("Polynomial is empty");
    else{
        struct node* temp;
        temp=head;
        while(temp!=NULL){
            printf("%dx^%d",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
                printf("+");
            else
                printf("\n");
        }
    }
}
struct node* add(struct node* head1,struct node* head2){
    struct node* head3=NULL;
    if(head1==NULL && head2==NULL){
        printf("Empty Polynomial ");
    }
    else{
        struct node* ptr1;
        struct node* ptr2;
        ptr1=head1;
        ptr2=head2;
        while (ptr1!=NULL && ptr2!=NULL){
            if(ptr1->expo==ptr2->expo){
                head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
                ptr1=ptr1->link;
                ptr2=ptr2->link;
                
            }
            else if(ptr1->expo>ptr2->expo){
               head3=insert(head3,ptr1->coeff,ptr1->expo);
                ptr1=ptr1->link;
            }
            else if(ptr1->expo<ptr2->expo){
                head3=insert(head3,ptr2->coeff,ptr2->expo);
                ptr2=ptr2->link;
            }
        }
        while(ptr1!=NULL){
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        while(ptr2!=NULL){
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
        
    }
    return head3;
}
struct node* mul(struct node*head1,struct node* head2){
    struct node* head4=NULL;
    struct node* ptr1;
    struct node* ptr2;
    ptr1=head1;
    int res1,res2;
    while(ptr1!=NULL){
        ptr2=head2;
        while(ptr2!=NULL){
            res1=ptr1->coeff*ptr2->coeff;
            res2=ptr1->expo*ptr2->expo;
            head4=insert(head4,res1,res2);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return head4;
}
void main(){
    struct node *head1=NULL;
    struct node* head2=NULL;
    struct node* head3=NULL;
    struct node* head4=NULL;
    printf("Enter the polynomial\n");
    head1=cre(head1);
    printf("The first polynomial is:\n");
    display(head1);
    head2=cre(head2);
    printf("The second polynomial is:\n");
    display(head2);
    head3=add(head1,head2);
    printf("The result of addition of polynomial 1 and 2 is:\n");
    display(head3);
    head4=mul(head1,head2);
    printf("The result of multuplication of polynomial 1 and 2 is:\n");
    display(head4);
}