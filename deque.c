#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Insert at front
void insertFront(int x) {
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if(front == 0) front = SIZE - 1;
    else front--;
    deque[front] = x;
}

// Insert at rear
void insertRear(int x) {
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if(front == -1) front = rear = 0;
    else if(rear == SIZE - 1) rear = 0;
    else rear++;
    deque[rear] = x;
}

// Delete from front
void deleteFront() {
    if(front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted: %d\n", deque[front]);
    if(front == rear) front = rear = -1;
    else if(front == SIZE - 1) front = 0;
    else front++;
}

// Delete from rear
void deleteRear() {
    if(front == -1) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted: %d\n", deque[rear]);
    if(front == rear) front = rear = -1;
    else if(rear == 0) rear = SIZE - 1;
    else rear--;
}

// Display deque
void display() {
    if(front == -1) {
        printf("Deque is empty\n");
        return;
    }
    int i = front;
    printf("Deque: ");
    while(1) {
        printf("%d ", deque[i]);
        if(i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int ch, x;

    while(1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

