// 6.⁠ ⁠write a program to merge 2 sorted single linked lists

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
    while(ptr != NULL)
    {
        printf("%d  ", ptr->x);
        ptr=ptr->next;
    }
    printf("\n");
    
}
struct Node* merge(struct Node* head1, struct Node* head2)
{
    struct Node* ptr1=head1;
    struct Node* ptr2=head2;
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=ptr;

    while(ptr1!=NULL && ptr2 != NULL)
    {
        if(ptr1->x < ptr2->x)
        {
            temp->next=ptr1;
            ptr1=ptr1->next;
            temp=temp->next;
        }
        else
        {
            temp->next=ptr2;
            ptr2=ptr2->next;
            temp=temp->next;
        }
    }
    if(ptr1 != NULL)
    {
        temp->next=ptr1;
    }
    else{
        temp->next=ptr2;
    }
    ptr=ptr->next;
    return ptr;
}

int main()
{
    struct Node* head1=create(1);
    insert(head1,3);
    insert(head1,4);
    insert(head1,5);
    insert(head1,7);
    insert(head1,11);
    printf("Linked List: \n");
    print(head1);
    struct Node* head2=create(2);
    insert(head2,6);
    insert(head2,8);
    insert(head2,9);
    insert(head2,10);
    insert(head2,12);
    printf("Linked List: \n");
    print(head2);
    struct Node* ptr= merge(head1, head2);
    print(ptr);
    
    return 0;
}