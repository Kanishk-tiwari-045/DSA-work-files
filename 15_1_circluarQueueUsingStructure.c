#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int n) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Overflow\n");
        return;
    }

    ptr->value = n;

    if (front == NULL && rear == NULL) {
        front = rear = ptr;
        rear->next = front; // Make rear point to front for circularity
    } else {
        rear->next = ptr;
        rear = ptr;
        rear->next = front; // Make rear point to front for circularity
    }

    printf("Enqueued %d\n", rear->value);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Underflow\n");
        return;
    }

    struct node *temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Update rear's next to point to the new front for circularity
    }

    free(temp);
}

void display() {
    struct node *current = front;

    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    do {
        printf("%d -> ", current->value);
        current = current->next;
    } while (current != front);

    printf("\n");
}

void FandR() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("\nFront: %d , Rear: %d\n", front->value, rear->value);
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();

    dequeue();
    display();
    
    FandR();

    return 0;
}
