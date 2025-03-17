// 1.⁠ ⁠write  program to find address of kth node from the last in single linked list.

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
void kthNode(struct Node* head, int k)
{
    struct Node* ptr=head;
    struct Node* ptr1=head;
    int n=0;
    while(ptr1 != NULL)
    {
        ptr1=ptr1->next;
        n++;
    }
    int i=0;
    if(k<n && k>=1)
    {
        while(i<=k)
        {
            i++;
            if(i==k)
            {
                break;
            }
            ptr=ptr->next;
        }
        printf("The %d th Node is: %d (Address: %p)",k,ptr->x,ptr);
    }
    else
    {
        printf("No element present on that Node");
    }
}

int main()
{
    struct Node* head=create(5);
    insert(head,7);
    insert(head,9);
    insert(head,11);
    insert(head,13);
    insert(head,15);
    insert(head,17);
    printf("Linked List: \n");
    print(head);
    kthNode(head,4);
    
    return 0;
}