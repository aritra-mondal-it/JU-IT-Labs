// 5, write  a program to find address of 1st intersecting node in single linked list with which other single linked list is attached.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int x;
    struct Node* next;
};
struct Node* create(int a)
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->x=a;
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
void print(struct Node* head)
{
    struct Node* ptr=head;
    printf("Linked List: \n");
    while(ptr != NULL)
    {
        printf("%d  ", ptr->x);
        ptr=ptr->next;
    }
    printf("\n");
    
}
int getlen(struct Node* head)
{
    struct Node* ptr=head;
    int i=0;
    while(ptr != NULL)
    {
        i++;
        ptr=ptr->next;
    }
    return i;
}
void intersection(struct Node* head1, struct Node* head2)
{
    int l1=getlen(head1);
    int l2=getlen(head2);

    if(l1>l2)
    {
        for(int i=0;i< l1-l2;i++)
        {
            head1=head1->next;
        }
    }
    else
    {
        for(int i=0;i< l2-l1;i++)
        {
            head2=head2->next;
        }
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1== head2)
        {
            printf("Intersection point found [%d], Address: %p",head1->x, head1);
            break;
        }
        head1=head1->next;
        head2=head2->next;
    }
}
int main()
{
    struct Node* head1=create(1);
    insert(head1,2);
    insert(head1,3);
    struct Node* ptr=create(4);
    head1->next->next->next=ptr;
    struct Node* head2=create(7);
    insert(head2,8);
    head2->next->next=head1->next->next->next;
    insert(head1,5);
    insert(head2,6);
    intersection(head1,head2);
    
    
    return 0;
}

