#include<stdio.h>
    #include<stdlib.h>
    struct node {
    int data;
    struct node *next;
    };
    void insert_node(struct node **,int);
    void print(struct node *);
    void merge(struct node **,struct node **,struct node **);
    int main()
    {
    struct node *ptr1,*ptr2,*ptr3=NULL;
    ptr1=ptr2=NULL;
    insert_node(&ptr1,23);
    insert_node(&ptr1,3);
    insert_node(&ptr1,78);
    insert_node(&ptr1,51);
    insert_node(&ptr1,90);
    print(ptr1);
    printf("\n");
    insert_node(&ptr2,15);
    insert_node(&ptr2,30);
    insert_node(&ptr2,88);
    print(ptr2);
    printf("\n");
    merge(&ptr1,&ptr2,&ptr3);
    print(ptr3);
    return 0;
    }
     
    void insert_node(struct node **head,int no)
    {
    struct node *p,*r;
     
    if(*head==NULL)
    {
    p=(struct node *)malloc(sizeof(struct node));
    p->data=no;
    p->next=NULL;
    *head=p;
    }
    else
    {
    p=*head;
    while(p->next!=NULL)
    p=p->next;
    p->next=(struct node *)malloc(sizeof(struct node));
    p=p->next;
    p->data=no;
    p->next=NULL;
    }
    }
     
    void print(struct node *head)
    {
    struct node *p;
    p=head;
    while(p!=NULL)
    {
    printf("%d ",p->data);
    p=p->next;
    }
    printf("\n");
    }
     
    void merge(struct node **ptr1,struct node **ptr2,struct node **ptr3)
    {
    struct node *temp;
    if(*ptr2==NULL && ptr1!=NULL) // if second list dosent exist
    {
    *ptr3=*ptr1;
    return;
    }
     
    else if(*ptr1==NULL && ptr2!=NULL) // if first list dosent exist
    {
    *ptr3=*ptr2;
    return ;
    }
     
    else if(*ptr1==NULL && ptr2==NULL)
    {
    return;
    }
    *ptr3=*ptr1;
    temp=*ptr1;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=*ptr2;
    }
