#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
// struct node* first;

void enqueue(int n)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("Overflown\n");
        return;
    }
    ptr->value = n;
    if (front == NULL && rear == NULL)
    {
        front = rear = ptr;
        front->next = NULL;
        rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }
    printf("Enqueued %d\n", rear->value);
}

void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct node *temp1 = front;
    front = front->next;
    free(temp1);
}

void display()
{
    struct node *current = front;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
}

void FandR(){
    printf("\nFront: %d ,Rear: %d\n",front->value,rear->value);
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    printf("\n");
    dequeue();
    display();
    FandR();
    return 0;
}
