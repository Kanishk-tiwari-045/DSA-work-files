#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int Max = 1; // Initial size
int* Stack; // Pointer to the dynamically allocated array

void SizeDec() {
    printf("Enter initial size of Array: ");
    scanf("%d", &Max);
    Stack = (int*)malloc(Max * sizeof(int)); // Allocate memory
}

void ResizeStack(int newSize) {
    Max = newSize;
    Stack = (int*)realloc(Stack, Max * sizeof(int)); // Reallocate memory
}

void Enqueue() {
    printf("Enqueue operation:\n");
    if ((front == 0 && rear == Max - 1) || front == rear + 1) {
        printf("Overflow\n");
    } else {
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else if (rear == Max - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        scanf("%d", &Stack[rear]);
        printf("Enqueued value: %d\n", Stack[rear]);
    }
}

void Dequeue() {
    printf("Dequeue operation:\n");
    if (front == -1 && rear == -1) {
        printf("Stack Underflow\n");
    } else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == Max - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void Display() {
    int i;
    printf("Performing display operation:\n");
    if (front == -1 && rear == -1) {
        printf("Stack Underflow\n");
    } else {
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d -> ", Stack[i]);
            }
        } else {
            for (i = front; i < Max; i++) {
                printf("%d -> ", Stack[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d -> ", Stack[i]);
            }
        }
        printf("\n");
    }
}

void Rear() {
    printf("Rear operation:\n");
    if (front == -1 && rear == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Peek value: %d\n", Stack[rear]);
    }
}

int main() {
    int n;
    SizeDec();
    printf("Stack Operations \n");

    do {
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Rear\n");
        printf("5. Change Size\n");
        printf("6. Exit\n");
        printf("Select the option: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                Rear();
                break;
            case 5:
                printf("Enter new size: ");
                int newSize;
                scanf("%d", &newSize);
                ResizeStack(newSize);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Enter a valid option.\n");
        }
    } while (n != 6);

    // Free the dynamically allocated memory before exiting
    free(Stack);

    return 0;
}
