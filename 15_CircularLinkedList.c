#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtFirst(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("UNDERFLOW\n");
        return;
    }
    ptr->val = value;

    if (head == NULL) {
        ptr->next = ptr;  // Circular reference to itself
        head = ptr;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
}

void insertAtLast(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("UNDERFLOW\n");
        return;
    }
    ptr->val = value;

    if (head == NULL) {
        ptr->next = ptr;  // Circular reference to itself
        head = ptr;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
    }
}

void deleteAtFirst() {
    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    if (head->next == head) {
        // If there's only one element in the list, set head to NULL
        free(head);
        head = NULL;
    } else {
        struct Node *ptr = head;
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = ptr->next;
        temp->next = head;
        free(ptr);
    }
}

void deleteLast() {
    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    struct Node *temp1 = head;
    struct Node *temp2 = head;

    while (temp1->next != head) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == head) {
        head = NULL;
    } else {
        temp2->next = head;
    }
    free(temp1);
}

// Insert a new node with the given value before the first occurrence of the target value.
void insertBefore(int target, int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("UNDERFLOW\n");
        return;
    }
    ptr->val = value;

    if (head == NULL) {
        ptr->next = ptr;  // Circular reference to itself
        head = ptr;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != head) {
        if (temp->val == target) {
            ptr->next = temp;
            if (prev == NULL) {
                // Insert before the head
                head = ptr;
            } else {
                prev->next = ptr;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->val == target) {
        ptr->next = temp;
        if (prev == NULL) {
            // Insert before the head
            head = ptr;
        } else {
            prev->next = ptr;
        }
    }
}

// Delete the first occurrence of the node with the given value and the node after it.
void deleteAfter(int target) {
    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head) {
        if (temp->val == target) {
            struct Node *toDelete = temp->next;
            if (toDelete == head) {
                // The node to delete is the head, update head accordingly.
                head = temp->next->next;
            }
            temp->next = temp->next->next;
            free(toDelete);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->val == target) {
        struct Node *toDelete = temp->next;
        if (toDelete == head) {
            // The node to delete is the head, update head accordingly.
            head = temp->next->next;
        }
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->val);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD Again\n");
}

int main() {
    insertAtFirst(3);
    insertAtFirst(66);
    insertAtLast(193);
    insertAtLast(52);
    insertAtLast(446);
    display();

    insertBefore(193, 999); // Insert 999 before 193
    insertAfter(193, 888);  // Insert 888 after 193
    display();

    deleteAtFirst();
    deleteLast();
    display();

    deleteAfter(999); // Delete the node with value 999 and the node after it
    display();

    return 0;
}
