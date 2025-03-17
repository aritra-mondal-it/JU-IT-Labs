// 2. write  program to move the last node of single linked list to 1st position.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int x;
    struct Node* next;
};
struct Node* create(int a)
{
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    head->x=a;
    head->next=NULL;
    return head;
}
void insert(struct Node* head, int a)
{
    struct Node* ptr=head;
    while(ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=(struct Node*)malloc(sizeof(struct Node));
    ptr->next->x=a;
    ptr->next->next=NULL;
}
void print(struct Node* head)
{
    struct Node* ptr=head;
    printf("Linked List: \n");
    while(ptr != NULL)
    {
        printf("%d  ",ptr->x);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node* swaplast(struct Node* head)
{
    struct Node* ptr= head;
    while(ptr->next->next != NULL)
    {
        ptr=ptr->next;
    }
    struct Node* temp=ptr->next;
    ptr->next=NULL;
    temp->next=head;
    head=temp;
    return head;
}
int main()
{
    struct Node* head=create(2);
    insert(head,4);
    insert(head,6);
    insert(head,8);
    insert(head,10);
    insert(head,12);
    insert(head,14);
    print(head);
    head=swaplast(head);
    print(head);
    return 0;
}