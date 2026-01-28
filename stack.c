#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

// Push operation
void push(int x) {
    if(top == SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed into stack\n", x);
}

// Pop operation
void pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack\n", stack[top--]);
}

// Display operation
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int ch, x;

    while(1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

