#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at end
void insert(int val) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;

    if(head == NULL) {
        head = n;
        return;
    }

    struct node *t = head;
    while(t->next != NULL)
        t = t->next;

    t->next = n;
}

// Delete by value
void deleteNode(int val) {
    struct node *t = head, *prev = NULL;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->data == val) {
        head = head->next;
        free(t);
        return;
    }

    while(t != NULL && t->data != val) {
        prev = t;
        t = t->next;
    }

    if(t == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = t->next;
    free(t);
}

// Display list
void display() {
    struct node *t = head;
    while(t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, x;

    while(1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if(ch == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            insert(x);
        }
        else if(ch == 2) {
            printf("Enter element to delete: ");
            scanf("%d", &x);
            deleteNode(x);
        }
        else if(ch == 3) {
            display();
        }
        else if(ch == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
}

