// 7. write  program for binary search in single linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* getMiddle(struct Node* start, struct Node* end) {
    struct Node* slow = start;
    struct Node* fast = start;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct Node* binarySearch(struct Node* head, int target) {
    struct Node* start = head;
    struct Node* end = NULL;

    while (start != end) {
        struct Node* mid = getMiddle(start, end);

        if (mid->data == target) {
            return mid;
        } else if (mid->data < target) {
            start = mid->next;
        } else {
            end = mid;
        }
    }

    return NULL;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    insert(&head, 11);

    printf("Linked List: ");
    printList(head);

    int target = 7;
    struct Node* result = binarySearch(head, target);

    if (result != NULL) {
        printf("Element %d found at address: %p\n", target, result);
    } else {
        printf("Element %d not found in the list.\n", target);
    }

    return 0;
}
