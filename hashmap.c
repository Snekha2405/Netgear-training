#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node {
    int key, value;
    struct node *next;
};

struct node* table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void put(int key, int value) {
    int index = hash(key);
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->key = key;
    n->value = value;
    n->next = table[index];
    table[index] = n;
}

int get(int key) {
    int index = hash(key);
    struct node *t = table[index];
    while(t != NULL) {
        if(t->key == key)
            return t->value;
        t = t->next;
    }
    return -1;
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        struct node *t = table[i];
        while(t != NULL) {
            printf("(%d,%d) ", t->key, t->value);
            t = t->next;
        }
    }
    printf("\n");
}

int main() {
    put(1, 100);
    put(2, 200);
    put(12, 300); // collision example
    display();

    printf("Value for key 2 = %d\n", get(2));
}

