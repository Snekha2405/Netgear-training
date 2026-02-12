#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = x;
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", queue[front++]);
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(ch == 2) dequeue();
        else if(ch == 3) display();
        else if(ch == 4) break;
    }
}

