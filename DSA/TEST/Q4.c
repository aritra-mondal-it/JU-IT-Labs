// 4. write a program to detect cycle in single linked list
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int x;
    struct Node* next;
};

struct Node* createNode(int a) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->x = a;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int a) {
    struct Node* newNode = createNode(a);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

int detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void printList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->x);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Linked List: ");
    printList(head);

    head->next->next->next->next = head->next;

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle in the linked list.\n");
    }

    return 0;
}
