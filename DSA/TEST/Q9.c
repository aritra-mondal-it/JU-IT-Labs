// 9. write  program in C to implement multiple stacks using single array
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top1, top2;
    int arr[MAX];
} MultiStack;

void initialize(MultiStack *ms) {
    ms->top1 = -1;
    ms->top2 = MAX;
}

void push1(MultiStack *ms, int value) {
    if (ms->top1 < ms->top2 - 1) {
        ms->arr[++(ms->top1)] = value;
        printf("Pushed %d to Stack 1\n", value);
    } else {
        printf("Stack Overflow for Stack 1\n");
    }
}

void push2(MultiStack *ms, int value) {
    if (ms->top1 < ms->top2 - 1) {
        ms->arr[--(ms->top2)] = value;
        printf("Pushed %d to Stack 2\n", value);
    } else {
        printf("Stack Overflow for Stack 2\n");
    }
}

int pop1(MultiStack *ms) {
    if (ms->top1 >= 0) {
        return ms->arr[(ms->top1)--];
    } else {
        printf("Stack Underflow for Stack 1\n");
        return -1;
    }
}

int pop2(MultiStack *ms) {
    if (ms->top2 < MAX) {
        return ms->arr[(ms->top2)++];
    } else {
        printf("Stack Underflow for Stack 2\n");
        return -1;
    }
}

int main() {
    MultiStack ms;
    initialize(&ms);

    push1(&ms, 10);
    push1(&ms, 20);
    push2(&ms, 30);
    push2(&ms, 40);

    printf("Popped from Stack 1: %d\n", pop1(&ms));
    printf("Popped from Stack 2: %d\n", pop2(&ms));

    return 0;
}
