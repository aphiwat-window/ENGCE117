#include <stdio.h>
#define MAX 100

void push(struct Stack* stack, int x);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
int isEmpty(struct Stack* stack);
int size(struct Stack* stack);

struct Stack {
    int arr[MAX];
    int top;
};

int main() {
    struct Stack stack;
    stack.top = -1;

    int n;
    printf("Enter number of elements to push into stack: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&stack, val);
    }

    printf("Top element is: %d\n", peek(&stack));
    printf("Size of stack: %d\n", size(&stack));

    printf("Popping elements:\n");
    while ( !isEmpty(&stack)) {
        printf("Popped element is: %d\n", pop(&stack));
    }

    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}

void push(struct Stack* stack, int x) {
    stack->top++; // เพิ่มค่า top ก่อน
    stack->arr[stack->top] = x; // ใส่ค่า x ที่ตำแหน่ง top
}

int pop(struct Stack* stack) {
    int popped_value = stack->arr[stack->top];
    stack->top = stack->top - 1;
    return popped_value;
}

int peek(struct Stack* stack) {
    return stack->arr[stack->top] ;
}
int isEmpty(struct Stack* stack) {
    if (stack->top == -1) { 
        return 1; 
    } else {
        return 0; 
    }
}

int size(struct Stack* stack) {
    return stack->top + 1;
}
