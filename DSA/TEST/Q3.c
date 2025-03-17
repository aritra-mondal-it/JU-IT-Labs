// 3. write a program to find address of middle node in single linked list.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int x;
    struct Node* next;
};
struct Node* create(int a)
{
    struct Node* head= (struct Node*)malloc(sizeof(struct Node));
    head->x=a;
    head->next=NULL;
    return head;
}
void insert(struct Node* head, int a)
{
    struct Node* ptr=head;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=(struct Node*)malloc(sizeof(struct Node));
    ptr->next->x=a;
    ptr->next->next=NULL;
}
void findmiddle(struct Node* head)
{
    struct Node*ptr=head;
    struct Node*ptr1=head;
    int n=1;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
        n++;
    }
    int i=1;
    while(i<=n/2)
    {
        if(i==n/2)
        {
            printf("Middle element is: %d(Address: %p)", ptr1->next->x, ptr1->next);
        }
        i++;
        ptr1=ptr1->next;
    }
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
int main()
{
    struct Node* head;
    head=create(1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    print(head);
    findmiddle(head);
    return 0;
}